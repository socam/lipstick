#ifndef SMSNOTIFIER_H
#define SMSNOTIFIER_H

#include "lipstickglobal.h"
#include "sms.h"
#include <QObject>

class QDeclarativeView;
class Notification;


/*!
 * \class CallNotifier
 *
 * \brief Presents SMS notifications.
 *
 */
class LIPSTICK_EXPORT SMSNotifier : public QObject
{
    Q_OBJECT
    Q_PROPERTY(uint count READ getCount NOTIFY modified)
    Q_PROPERTY(QString from READ getFrom  NOTIFY modified)

public:
    /*!
     * Creates a SMS notifier.
     *
     * \param parent the parent object
     */
    explicit SMSNotifier(QObject *parent = 0);

    /*!
     * Destroys the SMS notifier.
     */
    virtual ~SMSNotifier();

    /*!
     * Remove all received SMS notifications
     *
     */
    Q_INVOKABLE void clearSMSs();

    /*!
     * Get SMS count
     *
     */
    Q_INVOKABLE uint getCount();

    /*!
     * Get SMS origin (makes sense when count==1)
     *
     */
    Q_INVOKABLE QString getFrom();

    /*!
     * Show voicecall UI
     *
     */
    Q_INVOKABLE void showUI();





signals:

    //! Sent when the SMS list has changed.
    void modified();


private slots:

    //! Received when the SMS list has changed.
    void smsModified();




private:

    //! SMS count
    uint count;

    // SMS origin (makes sense when count==1)
    QString from;


};



#endif // SMSNOTIFIER_H
