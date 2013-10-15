#include <QObject>
#include <QtDeclarative>
#include <QAbstractItemModel>

#ifndef QTDBUSNOTIFIER_H
#define QTDBUSNOTIFIER_H

#endif // QTDBUSNOTIFIER_H


class Q_DECL_EXPORT QtDbusNotifier : public QObject{

    Q_OBJECT

public:

    QtDbusNotifier();

    Q_INVOKABLE
    void notifyScreenChanged(int i);



};
