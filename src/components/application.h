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

#ifndef APPLICATION_H
#define APPLICATION_H

#include "lipstickglobal.h"
#include <QStringList>
#include <QDateTime>
#include <QVariantHash>
#include <MDesktopEntry>


/*!
 * An object for storing information about an installed application.
 */
class LIPSTICK_EXPORT Application : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString filePath READ filePath)
    Q_PROPERTY(QString appIcon READ appIcon)
    Q_PROPERTY(QString exec READ exec)

public:
    /*!
     * Creates an object for storing information about an application.
     *
     * \param filePath path of the application file descriptor
     * \param appIcon icon ID of the application
     * \param exec Command line of the application
     * \param parent the parent QObject
     */
    Application(MDesktopEntry* desktopEntry, QObject *parent);

    /*!
     * Creates a new uninitialized representation of an application.
     *
     * \param parent the parent QObject
     */
    Application(QObject *parent = 0);


    //! Returns the path of the application file descriptor
    QString filePath() const;

    //! Returns the icon ID of the application
    QString appIcon() const;

    //! Returns the command line of the application
    QString exec() const;

    MDesktopEntry* getDesktopEntry();


    //! \internal
    /*!
     * Creates a copy of an existing representation of a application.
     * This constructor should only be used for populating the application
     * list from D-Bus structures.
     *
     * \param application the application representation to a create copy of
     */
    explicit Application(const Application &Application);

    //! \internal_end


private:

    MDesktopEntry* desktopEntry_;

};

Q_DECLARE_METATYPE(Application)
Q_DECLARE_METATYPE(QList<Application>)

#endif // APPLICATION_H
