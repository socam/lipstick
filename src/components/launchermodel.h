
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

#ifndef LAUNCHERMODEL_H
#define LAUNCHERMODEL_H

#include <QObject>
#include "launcheritem.h"
#include "application.h"
#include "utilities/qobjectlistmodel.h"
#include "lipstickglobal.h"
#include <string>

using namespace std;

class QFileSystemWatcher;

class LIPSTICK_EXPORT LauncherModel : public QObjectListModel
{
    Q_OBJECT
    Q_DISABLE_COPY(LauncherModel)

    QFileSystemWatcher *_fileSystemWatcher;

private slots:
    void newApp(Application* app);
    void removedApp(Application* app);

private:
    static const QSet<LauncherItem*> entries;

public:
    explicit LauncherModel(QObject *parent = 0);
    virtual ~LauncherModel();

    QStringList directories() const;
    void setDirectories(QStringList);


public slots:
    void savePositions();



signals:
    void directoriesChanged();
    void newAppIcon(string cmd, string icon);


private:
    QMap<int, LauncherItem *> *itemsWithPositions;


};


#endif // LAUNCHERMODEL_H
