#############################################################################
# Makefile for building: ut_notification
# Generated by qmake (2.01a) (Qt 4.8.3) on: Tue Jun 18 09:58:43 2013
# Project:  ut_notification.pro
# Template: app
# Command: /usr/lib/qt4/bin/qmake -o Makefile ut_notification.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DUNIT_TEST -DQT_NO_DEBUG -DQT_DBUS_LIB -DQT_TESTLIB_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -Werror -g -std=c++0x -fPIC -fvisibility=hidden -fvisibility-inlines-hidden -Wno-error=format-security -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtTest -I/usr/include/qt4/QtDBus -I/usr/include/qt4 -I../../src -I../stubs -I../../src/notifications -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtDBus -lQtTest -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = ut_notification.cpp \
		../../src/notifications/notification.cpp \
		../stubs/stubbase.cpp moc_ut_notification.cpp \
		moc_notification.cpp \
		moc_notificationmanager.cpp
OBJECTS       = ut_notification.o \
		notification.o \
		stubbase.o \
		moc_ut_notification.o \
		moc_notification.o \
		moc_notificationmanager.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		../common.pri \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/dbusinterfaces.prf \
		/usr/share/qt4/mkspecs/features/dbusadaptors.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		ut_notification.pro
QMAKE_TARGET  = ut_notification
DESTDIR       = 
TARGET        = ut_notification

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: ut_notification.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		../common.pri \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/dbusinterfaces.prf \
		/usr/share/qt4/mkspecs/features/dbusadaptors.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtDBus.prl \
		/usr/lib/libQtTest.prl \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -o Makefile ut_notification.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
../common.pri:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/dbusinterfaces.prf:
/usr/share/qt4/mkspecs/features/dbusadaptors.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtDBus.prl:
/usr/lib/libQtTest.prl:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile ut_notification.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/ut_notification1.0.0 || $(MKDIR) .tmp/ut_notification1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/ut_notification1.0.0/ && $(COPY_FILE) --parents ut_notification.h ../../src/notifications/notification.h ../../src/notifications/notificationmanager.h ../stubs/qdbusargument_fake.h .tmp/ut_notification1.0.0/ && $(COPY_FILE) --parents ut_notification.cpp ../../src/notifications/notification.cpp ../stubs/stubbase.cpp .tmp/ut_notification1.0.0/ && (cd `dirname .tmp/ut_notification1.0.0` && $(TAR) ut_notification1.0.0.tar ut_notification1.0.0 && $(COMPRESS) ut_notification1.0.0.tar) && $(MOVE) `dirname .tmp/ut_notification1.0.0`/ut_notification1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/ut_notification1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_ut_notification.cpp moc_notification.cpp moc_notificationmanager.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_ut_notification.cpp moc_notification.cpp moc_notificationmanager.cpp
moc_ut_notification.cpp: ut_notification.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) ut_notification.h -o moc_ut_notification.cpp

moc_notification.cpp: ../../src/lipstickglobal.h \
		../../src/notifications/notification.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) ../../src/notifications/notification.h -o moc_notification.cpp

moc_notificationmanager.cpp: ../../src/lipstickglobal.h \
		../../src/notifications/notification.h \
		../../src/notifications/notificationmanager.h
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) ../../src/notifications/notificationmanager.h -o moc_notificationmanager.cpp

compiler_dbus_interface_source_make_all:
compiler_dbus_interface_source_clean:
compiler_dbus_adaptor_source_make_all:
compiler_dbus_adaptor_source_clean:
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_dbus_interface_header_make_all:
compiler_dbus_interface_header_clean:
compiler_dbus_interface_moc_make_all:
compiler_dbus_interface_moc_clean:
compiler_dbus_adaptor_header_make_all:
compiler_dbus_adaptor_header_clean:
compiler_dbus_adaptor_moc_make_all:
compiler_dbus_adaptor_moc_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

ut_notification.o: ut_notification.cpp ../stubs/qdbusargument_fake.h \
		ut_notification.h \
		../stubs/notificationmanager_stub.h \
		../stubs/stubbase.h \
		../stubs/parameter.h \
		../stubs/methodcall.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ut_notification.o ut_notification.cpp

notification.o: ../../src/notifications/notification.cpp ../../src/notifications/notificationmanager.h \
		../../src/lipstickglobal.h \
		../../src/notifications/notification.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o notification.o ../../src/notifications/notification.cpp

stubbase.o: ../stubs/stubbase.cpp ../stubs/stubbase.h \
		../stubs/parameter.h \
		../stubs/methodcall.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o stubbase.o ../stubs/stubbase.cpp

moc_ut_notification.o: moc_ut_notification.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ut_notification.o moc_ut_notification.cpp

moc_notification.o: moc_notification.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_notification.o moc_notification.cpp

moc_notificationmanager.o: moc_notificationmanager.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_notificationmanager.o moc_notificationmanager.cpp

####### Install

install_target: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/opt/tests/lipstick-tests/ || $(MKDIR) $(INSTALL_ROOT)/opt/tests/lipstick-tests/ 
	-$(INSTALL_PROGRAM) "$(QMAKE_TARGET)" "$(INSTALL_ROOT)/opt/tests/lipstick-tests/$(QMAKE_TARGET)"
	-$(STRIP) "$(INSTALL_ROOT)/opt/tests/lipstick-tests/$(QMAKE_TARGET)"

uninstall_target:  FORCE
	-$(DEL_FILE) "$(INSTALL_ROOT)/opt/tests/lipstick-tests/$(QMAKE_TARGET)"
	-$(DEL_DIR) $(INSTALL_ROOT)/opt/tests/lipstick-tests/ 


install:  install_target  FORCE

uninstall: uninstall_target   FORCE

FORCE:

