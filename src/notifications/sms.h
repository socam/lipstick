#ifndef SMS_H
#define SMS_H


#include "lipstickglobal.h"
#include <QObject>

class LIPSTICK_EXPORT SMS : public QObject
{

    Q_OBJECT
    Q_PROPERTY(QString from READ from)


public:

    /*!
     * Creates an object for storing information about a single SMS.
     *
     * \param from Caller number or contact name
     */
    SMS(const QString &from, QObject *parent = 0);

    /*!
     * Creates a new uninitialized representation of a SMS.
     *
     * \param parent the parent QObject
     */
    SMS(QObject *parent = 0);

    //! Returns the caller number or contact name
    QString from() const;

    //! Sets the caller number or contact name
    void setFrom(const QString &from);

private:

    //! Name of the application sending the notification
    QString from_;

};


#endif // SMS_H
