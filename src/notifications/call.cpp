#include <QDBusArgument>
#include "notificationmanager.h"
#include "call.h"

Call::Call(const QString &from, QObject *parent) :
    QObject(parent),
    from_(from)
{
}

Call::Call(QObject *parent) :
    QObject(parent)
{
}

QString Call::from() const
{
    return from_;
}

void Call::setFrom(const QString &from)
{
    from_ = from;
}
