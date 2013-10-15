#ifndef FEEDTEMPLATENOTIFIER_H
#define FEEDTEMPLATENOTIFIER_H


#include "lipstickglobal.h"
#include <QObject>

class QDeclarativeView;
class Notification;


/*!
 * \class FeedTemplateNotifier
 *
 * \brief Listens for feed template notifications
 *
 */
class LIPSTICK_EXPORT FeedTemplateNotifier : public QObject
{
    Q_OBJECT


public:
    /*!
     * Creates a FeedTemplateNotifier object
     *
     * \param parent the parent object
     */
    explicit FeedTemplateNotifier(QObject *parent = 0);

    /*!
     * Destroys the SMS notifier.
     */
    virtual ~FeedTemplateNotifier();


signals:

    //! Sent when the SMS list has changed.
    void modified();


private slots:

    //! Received when the SMS list has changed.
    void feedTemplateModified();

};




#endif // FEEDTEMPLATENOTIFIER_H
