#ifndef CALL_H
#define CALL_H

#include "lipstickglobal.h"
#include <QObject>

class LIPSTICK_EXPORT Call : public QObject
{

    Q_OBJECT
    Q_PROPERTY(QString from READ from)


public:

    /*!
     * Creates an object for storing information about a single call.
     *
     * \param from Caller number or contact name
     */
    Call(const QString &from, QObject *parent = 0);

    /*!
     * Creates a new uninitialized representation of a call.
     *
     * \param parent the parent QObject
     */
    Call(QObject *parent = 0);

    //! Returns the caller number or contact name
    QString from() const;

    //! Sets the caller number or contact name
    void setFrom(const QString &from);

private:

    //! Name of the application sending the notification
    QString from_;

};

#endif // CALL_H
