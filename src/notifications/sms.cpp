#include <QDBusArgument>
#include "notificationmanager.h"
#include "sms.h"

SMS::SMS(const QString &from, QObject *parent) :
    QObject(parent),
    from_(from)
{
}

SMS::SMS(QObject *parent) :
    QObject(parent)
{
}

QString SMS::from() const
{
    return from_;
}

void SMS::setFrom(const QString &from)
{
    from_ = from;
}

