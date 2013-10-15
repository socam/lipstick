
#include <QApplication>
#include <QDesktopWidget>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QDBusConnection>
#include <QDBusArgument>
#include <QDBusInterface>
#include "notifications/notificationmanager.h"
#include "smsnotifier.h"

#include <iostream>
using namespace std;

SMSNotifier::SMSNotifier(QObject *parent) :
    QObject(parent)
{
    connect(NotificationManager::instance(), SIGNAL(smsModified()), this, SLOT(smsModified()));
    smsModified();
}

SMSNotifier::~SMSNotifier()
{

}

void SMSNotifier::smsModified() {
    cout << "SMSNotifier::smsModified" << endl;
    this->count = NotificationManager::instance()->getSMSs().size();
    this->from = "";
    if(count==1) {
        this->from = NotificationManager::instance()->getSMSs().at(0)->from();
    }
    emit modified();
    cout << "SMSNotifier::smsModified count=" << this->count << " from=" << from.toUtf8().data() << endl;
}


void SMSNotifier::clearSMSs() {
    cout << "SMSNotifier::clearSMSs()" << endl;
    NotificationManager::instance()->clearSMSs();
    smsModified();
}


uint SMSNotifier::getCount() {
    cout << "SMSNotifier::getCount: " << this->count << endl;
     return this->count;
}

QString SMSNotifier::getFrom() {
     return this->from;
}

void SMSNotifier::showUI() {
    QDBusConnection connection = QDBusConnection::sessionBus();
    if (connection.isConnected()) {
        QDBusInterface* dbusIface = new QDBusInterface("org.nemomobile.qmlmessages", "/",
                                               "org.nemomobile.qmlmessages", connection);
        dbusIface->call(QDBus::NoBlock, "showGroupsWindow");
    }
}


