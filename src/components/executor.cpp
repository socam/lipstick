
#include <iostream>
#include "executor.h"
#include <QProcess>

using namespace std;

Executor::Executor() {


}

void Executor::execute(QString cmd) {

    cout << "Execute:" << cmd.toUtf8().data() << endl;
    QProcess::startDetached(cmd);

}
