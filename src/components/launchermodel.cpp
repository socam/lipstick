
// This file is part of lipstick, a QML desktop library
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License version 2.1 as published by the Free Software Foundation
// and appearing in the file LICENSE.LGPL included in the packaging
// of this file.
//
// This code is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Lesser General Public License for more details.
//
// Copyright (c) 2012, Timur Kristóf <venemo@fedoraproject.org>

#include <QDebug>
#include <QSettings>
#include <MDesktopEntry>

#include "launchermodel.h"

#include "applicationmanager.h"

// Define this if you'd like to see debug messages from the launcher
#ifdef DEBUG_LAUNCHER
#define LAUNCHER_DEBUG(things) qDebug() << Q_FUNC_INFO << things
#else
#define LAUNCHER_DEBUG(things)
#endif

LauncherModel::LauncherModel(QObject *parent) :
    QObjectListModel(parent)
{

    qWarning() << Q_FUNC_INFO << "LAUNCHER MODEL constructor" << endl;

    ApplicationManager *appmanager = ApplicationManager::instance();
    connect(appmanager, SIGNAL(newApp(Application*)), this, SLOT(newApp(Application*)));
    connect(appmanager, SIGNAL(removedApp(Application*)), this, SLOT(removedApp(Application*)));
    connect(this, SIGNAL(rowsMoved(const QModelIndex&,int,int,const QModelIndex&,int)), this, SLOT(savePositions()));

    itemsWithPositions = new QMap<int, LauncherItem *>();

    QSet<Application *> apps = appmanager->getApplications();
    for (QSet<Application *>::ConstIterator it = apps.constBegin();
         it != apps.constEnd(); ++it) {
        newApp(*it);
    }

}

LauncherModel::~LauncherModel()
{
}

void LauncherModel::newApp(Application *app) {

    qWarning() << Q_FUNC_INFO << "newApp path=" << app->filePath() << " icon=" << app->appIcon() << " exec=" << app->exec() << endl;

    QSettings launcherSettings("nemomobile", "lipstick");
    QSettings globalSettings("/usr/share/lipstick/lipstick.conf", QSettings::IniFormat);

    LAUNCHER_DEBUG("Creating LauncherItem for desktop entry" << fileInfo.absoluteFilePath());
    LauncherItem *item = new LauncherItem(app->getDesktopEntry(), this);
    this->addItem(item);

    QVariant pos = launcherSettings.value("LauncherOrder/" + item->filePath());

    // fall back to vendor configuration if the user hasn't specified a location
    if (!pos.isValid())
        pos = globalSettings.value("LauncherOrder/" + item->filePath());

    if (!pos.isValid())
        return;

    int gridPos = pos.toInt();
    itemsWithPositions->insert(gridPos, item);
     qDebug() << Q_FUNC_INFO << "Planned move of " << item->filePath() << " to " << gridPos;

    // QMap is key-ordered, the int here is the desired position in the launcher we want the item to appear
    // so, we'll iterate from the lowest desired position to the highest, and move the items there.
    for (QMap<int, LauncherItem *>::ConstIterator it = itemsWithPositions->constBegin();
         it != itemsWithPositions->constEnd(); ++it) {
        LauncherItem *item = it.value();
        int gridPos = it.key();
        qDebug() << Q_FUNC_INFO << "Moving " << item->filePath() << " to " << gridPos;

        if (gridPos < 0 || gridPos >= itemCount()) {
            qWarning() << Q_FUNC_INFO << "Invalid planned position for " << item->filePath();
            continue;
        }

        int currentPos = indexOf(item);
        Q_ASSERT(currentPos >= 0);
        if (currentPos == -1)
            continue;

        if (gridPos == currentPos)
            continue;

        move(currentPos, gridPos);
    }

    savePositions();

}


void LauncherModel::removedApp(Application *app) {

    qWarning() << Q_FUNC_INFO << "removedApp path=" << app->filePath() << " icon=" << app->appIcon() << " exec=" << app->exec() << endl;

    QSettings launcherSettings("nemomobile", "lipstick");
    QSettings globalSettings("/usr/share/lipstick/lipstick.conf", QSettings::IniFormat);

    QList<LauncherItem *> *currentLauncherList = getList<LauncherItem>();

    // Finding removed desktop entries
    foreach (LauncherItem *item, *currentLauncherList) {
        if (app->filePath() == item->filePath()) {

            removeItem(item);

            QVariant pos = launcherSettings.value("LauncherOrder/" + app->filePath());

            // fall back to vendor configuration if the user hasn't specified a location
            if (!pos.isValid())
                pos = globalSettings.value("LauncherOrder/" + app->filePath());

            if (!pos.isValid())
                continue;

            int gridPos = pos.toInt();
            itemsWithPositions->insert(gridPos, item);
            LAUNCHER_DEBUG("Planned move of " << item->filePath() << " to " << gridPos);

            // QMap is key-ordered, the int here is the desired position in the launcher we want the item to appear
            // so, we'll iterate from the lowest desired position to the highest, and move the items there.
            for (QMap<int, LauncherItem *>::ConstIterator it = itemsWithPositions->constBegin();
                 it != itemsWithPositions->constEnd(); ++it) {
                LauncherItem *item = it.value();
                int gridPos = it.key();
                LAUNCHER_DEBUG("Moving " << item->filePath() << " to " << gridPos);

                if (gridPos < 0 || gridPos >= itemCount()) {
                    qWarning() << Q_FUNC_INFO << "Invalid planned position for " << item->filePath();
                    continue;
                }

                int currentPos = indexOf(item);
                Q_ASSERT(currentPos >= 0);
                if (currentPos == -1)
                    continue;

                if (gridPos == currentPos)
                    continue;

                move(currentPos, gridPos);
            }

            savePositions();

            break;

        }

    }




}


void LauncherModel::savePositions()
{
    QSettings launcherSettings("nemomobile", "lipstick");
    QList<LauncherItem *> *currentLauncherList = getList<LauncherItem>();

    int pos = 0;
    foreach (LauncherItem *item, *currentLauncherList) {
        launcherSettings.setValue("LauncherOrder/" + item->filePath(), pos);
        ++pos;
    }

    launcherSettings.sync();
}

