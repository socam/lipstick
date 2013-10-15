
#include <QApplication>
#include <QDesktopWidget>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QDBusConnection>
#include <QDBusArgument>
#include <QDBusInterface>
#include "notifications/notificationmanager.h"
#include "feedtemplatenotifier.h"

#include <iostream>
using namespace std;

FeedTemplateNotifier::FeedTemplateNotifier(QObject *parent) :
    QObject(parent)
{
    connect(NotificationManager::instance(), SIGNAL(feedTemplatesModified()), this, SLOT(feedTemplateModified()));
    //emit modified();
}

FeedTemplateNotifier::~FeedTemplateNotifier()
{

}

void FeedTemplateNotifier::feedTemplateModified() {
    cout << "FeedTemplateNotifier::feedTemplateModified()" << endl;
    emit modified();
}


