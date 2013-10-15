/***************************************************************************
**
** Copyright (C) 2012 Jolla Ltd.
** Contact: Robin Burchell <robin.burchell@jollamobile.com>
**
** This file is part of lipstick.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file LICENSE.LGPL included in the packaging
** of this file.
**
****************************************************************************/

#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <mremoteaction.h>
#include <MDesktopEntry>
#include "applicationmanager.h"

#define DEFAULT_APP_PATH "/usr/share/applications"


ApplicationManager *ApplicationManager::instance_ = 0;

ApplicationManager *ApplicationManager::instance()
{

    if (instance_ == 0) {
        instance_ = new ApplicationManager(qApp);
    }
    return instance_;
}

ApplicationManager::ApplicationManager(QObject *parent) :
    QObject(parent)
{

    // This is the most common path for .desktop files in most distributions
    QString defaultAppsPath(DEFAULT_APP_PATH);

    // Setting up the file system wacher
    fileSystemWatcher_ = new QFileSystemWatcher();
    fileSystemWatcher_->addPath(defaultAppsPath);
    monitoredDirectoryChanged(defaultAppsPath);
    connect(fileSystemWatcher_, SIGNAL(directoryChanged(QString)), this, SLOT(monitoredDirectoryChanged(QString)));

    connect(this, SIGNAL(rowsMoved(const QModelIndex&,int,int,const QModelIndex&,int)), this, SLOT(savePositions()));

    char* pPath;
    pPath = getenv ("PATH");
    if (pPath!=NULL) {

        //qDebug() << Q_FUNC_INFO << "PATH found";
        QString path(pPath);
        QStringList entries = path.split(":");

        foreach (QString entry, entries) {
            //qDebug() << Q_FUNC_INFO << "PATH entry:" << entry;
            if(!entry.endsWith("/")) {
                entry.append("/");
                //qDebug() << Q_FUNC_INFO << "PATH entry(2):" << entry;
            }
            pathEntries.append(entry);
        }


    }

}

ApplicationManager::~ApplicationManager()
{

}

QSet<Application *> ApplicationManager::getApplications() {
    QSet<Application *> apps(applications_);
    return apps;
}

Application* ApplicationManager::findApplication(QString cmd) const {

    //qDebug() << Q_FUNC_INFO << "find application:" << cmd;

    QString cmdWithoutParams(cmd);
    cmdWithoutParams = cmdWithoutParams.left(cmdWithoutParams.indexOf(QRegExp("\\s"))).trimmed();

    QString shortCmd;
    if(cmdWithoutParams.contains("/")) {
        //qDebug() << Q_FUNC_INFO << " cmd includes slashes!!!!!!!!!!!";
        foreach (QString entry, pathEntries) {
            //qDebug() << Q_FUNC_INFO << " remove " << entry.toUtf8().data();
            shortCmd = cmdWithoutParams;
            shortCmd.replace(entry, "");
            //qDebug() << Q_FUNC_INFO << " replaced(1): " << shortCmd  ;
            if(shortCmd.contains("/")) {
                shortCmd = "";
            } else{
                break;
            }
            //qDebug() << Q_FUNC_INFO << " short: " << shortCmd  ;
        }
    }

    QString regexStr(QString("(^|\\s)(").append(cmdWithoutParams));
    if(!shortCmd.isEmpty()) {
        regexStr.append("|").append(shortCmd);
    }
    regexStr.append(")(\\b|\\s)");

    QRegExp regex(regexStr);
    //qDebug() << Q_FUNC_INFO << " text to find=[" << regexStr.toUtf8().data() << "]";

    QSet<Application*>::const_iterator it = applications_.begin();

    while (it != applications_.end()) {
        Application* item = (*it);
        //qDebug() << Q_FUNC_INFO << " check app: exec=[" << item->exec() << "]";
        it++;
        QString exec(item->exec());
        if(exec.contains(regex)) {
            //qDebug() << Q_FUNC_INFO << " matches!";
            return item;
        }

    }

    return NULL;
}

void ApplicationManager::monitoredDirectoryChanged(QString changedPath)
{
    QDir directory(changedPath);
    directory.setFilter(QDir::Files);
    QFileInfoList fileInfoList = directory.entryInfoList();
    QSet<Application*> currentApps(applications_);

    // Finding removed desktop entries
    foreach (Application *item, currentApps) {
        if (!item->filePath().startsWith(changedPath))
            continue;

        bool foundOnDisk = false;
        foreach (const QFileInfo &fileInfo, fileInfoList) {
            if (fileInfo.absoluteFilePath() == item->filePath())
                foundOnDisk = true;
        }

        if (!foundOnDisk) {
            //qDebug() << Q_FUNC_INFO << item->filePath() << " removed from disk";
            applications_.remove(item);
            emit removedApp(item);
            //TODO delete item will cause SIGSEGV??
        }
    }

    // Finding newly added desktop entries
    foreach (const QFileInfo &fileInfo, fileInfoList) {
        // Skip files which are not desktop entries
        if (!fileInfo.fileName().endsWith(".desktop"))
            continue;

        bool foundInModel = false;
        foreach (Application *item, currentApps) {
            if (fileInfo.absoluteFilePath() == item->filePath()) {
                foundInModel = true;
                break;
            }
        }

        if (!foundInModel) {

            //qDebug() << Q_FUNC_INFO << "Read desktop entry: " << fileInfo.absoluteFilePath();
            MDesktopEntry* desktopEntry = new MDesktopEntry(fileInfo.absoluteFilePath());

            if (!desktopEntry->isValid()) {
                //qDebug() << Q_FUNC_INFO << "Item " << fileInfo.absoluteFilePath() << " is not valid";
                delete desktopEntry;
                continue;
            } else {
                Application* app = new Application(desktopEntry, this);
                applications_.insert(app);
                emit newApp(app);
            }

        }
    }

}


