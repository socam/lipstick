#ifndef CALLNOTIFIER_H
#define CALLNOTIFIER_H

#include "lipstickglobal.h"
#include "call.h"
#include <QObject>

class QDeclarativeView;
class Notification;


/*!
 * \class CallNotifier
 *
 * \brief Presents missed call notifications.
 *
 */
class LIPSTICK_EXPORT CallNotifier : public QObject
{
    Q_OBJECT
    Q_PROPERTY(uint count READ getCount NOTIFY modified)
    Q_PROPERTY(QString from READ getFrom)

public:
    /*!
     * Creates a call notifier.
     *
     * \param parent the parent object
     */
    explicit CallNotifier(QObject *parent = 0);

    /*!
     * Destroys the call notifier.
     */
    virtual ~CallNotifier();

    /*!
     * Remove all missed calls
     *
     */
    Q_INVOKABLE void clearCalls();

    /*!
     * Get call count
     *
     */
    Q_INVOKABLE uint getCount();

    /*!
     * Get call origin (makes sense when count==1)
     *
     */
    Q_INVOKABLE QString getFrom();


    /*!
     * Show voicecall UI
     *
     */
    Q_INVOKABLE void showUI();






signals:

    //! Sent when the call list has changed.
    void modified();


private slots:

    //! Received when the call list has changed.
    void callsModified();




private:

    //! Call count
    uint count;

    // Call origin (makes sense when count==1)
    QString from;


};


#endif // CALLNOTIFIER_H
