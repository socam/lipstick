
#include <QApplication>
#include <QDesktopWidget>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QDBusConnection>
#include <QDBusArgument>
#include <QDBusInterface>

#include "notifications/notificationmanager.h"
#include "callnotifier.h"

#include <iostream>
using namespace std;

CallNotifier::CallNotifier(QObject *parent) :
    QObject(parent)
{
    connect(NotificationManager::instance(), SIGNAL(callsModified()), this, SLOT(callsModified()));
    callsModified();
}

CallNotifier::~CallNotifier()
{

}

void CallNotifier::callsModified() {
    cout << "CallNotifier::callsModified" << endl;
    this->count = NotificationManager::instance()->getCalls().size();
    this->from = "";
    if(count==1) {
        this->from = NotificationManager::instance()->getCalls().at(0)->from();
    }
    emit modified();
    cout << "CallNotifier::callsModified count=" << this->count << " from=" << from.toUtf8().data() << endl;
}


void CallNotifier::clearCalls() {
    cout << "CallNotifier::clearCalls()" << endl;
    NotificationManager::instance()->clearCalls();
    callsModified();
}


uint CallNotifier::getCount() {
    cout << "CallNotifier::getCount: " << this->count << endl;
     return this->count;
}


QString CallNotifier::getFrom() {
     return this->from;
}


void CallNotifier::showUI() {
    QDBusConnection connection = QDBusConnection::sessionBus();
    if (connection.isConnected()) {
        QDBusInterface* dbusIface = new QDBusInterface("org.nemomobile.voicecall.ui", "/",
                                               "org.nemomobile.voicecall.ui", connection);
        dbusIface->call(QDBus::NoBlock, "show");
    }
}
