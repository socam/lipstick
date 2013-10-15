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

#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include "lipstickglobal.h"
#include "application.h"
#include <QObject>
#include <QTimer>
#include <QSet>
#include <QFileSystemWatcher>
#include <QDebug>
#include <QSettings>
#include <MDesktopEntry>


class CategoryDefinitionStore;
class QSqlDatabase;

/*!
 * \class ApplicationManager
 *
 * \brief The application manager TODOTODOTODO
 *
 */
class LIPSTICK_EXPORT ApplicationManager : public QObject
{
    Q_OBJECT

public:


    /*!
     * Returns a singleton instance of the application manager.
     *
     * \return an instance of the application manager
     */
    static ApplicationManager *instance();

    /*!
     * Returns an application which "exec" contains the given command line.
     *
     * \param cmd Command line
     * \return an application which "exec" contains the given command line
     */
    Application *findApplication(QString cmd) const;

    QSet<Application *> getApplications();


signals:

    void newApp(Application* app);

    void removedApp(Application* app);


private slots:

    void monitoredDirectoryChanged(QString);

private:
    /*!
     * Creates a new application manager.
     *
     * \param parent the parent object
     */
    explicit ApplicationManager(QObject *parent = 0);

    //! Destroys the application manager.
    virtual ~ApplicationManager();




    //! The singleton application manager instance
    static ApplicationManager *instance_;

    //! Applications
    QSet<Application *> applications_;


    QFileSystemWatcher *fileSystemWatcher_;

    QStringList pathEntries;


#ifdef UNIT_TEST
    friend class Ut_ApplicationManager;
#endif
};

#endif // APPLICATIONMANAGER_H
