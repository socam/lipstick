#include <QObject>
#include <QtDeclarative>
#include <QAbstractItemModel>
#include <QString>

#ifndef EXECUTER_H
#define EXECUTER_H

class Q_DECL_EXPORT Executor : public QObject {

    Q_OBJECT

public:

    Executor();

    Q_INVOKABLE
    void execute(QString cmd);

};


#endif //EXECUTER_H
