#include <iostream>
#include "qtdbusnotifier.h"
#include <QDBusMessage>
#include <QDBusConnection>
#include <QDBusArgument>
#include <dbus/dbus-glib-lowlevel.h>
#include <QDBusInterface>

using namespace std;

QtDbusNotifier::QtDbusNotifier() {


}

void QtDbusNotifier::notifyScreenChanged(int i) {

    QDBusConnection connection = QDBusConnection::sessionBus();
    if (connection.isConnected()) {
        QDBusInterface* dbusIface = new QDBusInterface("zed.socam.ScreenPagerStatus", "/screenpagerstatus",
                                               "zed.socam.ScreenPagerStatus", connection);
        unsigned int index = (unsigned int) i;
        dbusIface->call(QDBus::NoBlock, "setCurrentPage", index);

    }

}
