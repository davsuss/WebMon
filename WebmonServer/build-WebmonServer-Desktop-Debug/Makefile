#############################################################################
# Makefile for building: WebmonServer
# Generated by qmake (2.01a) (Qt 4.8.5) on: Wed Dec 11 13:33:19 2013
# Project:  ../WebmonServer/WebmonServer.pro
# Template: app
# Command: /usr/local/Trolltech/Qt-4.8.5/bin/qmake -spec /usr/local/Trolltech/Qt-4.8.5/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile ../WebmonServer/WebmonServer.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_SQL_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/local/Trolltech/Qt-4.8.5/mkspecs/linux-g++ -I../WebmonServer -I/usr/local/Trolltech/Qt-4.8.5/include/QtCore -I/usr/local/Trolltech/Qt-4.8.5/include/QtNetwork -I/usr/local/Trolltech/Qt-4.8.5/include/QtGui -I/usr/local/Trolltech/Qt-4.8.5/include/QtSql -I/usr/local/Trolltech/Qt-4.8.5/include -I. -I../WebmonServer -I.
LINK          = g++
LFLAGS        = -Wl,-rpath,/usr/local/Trolltech/Qt-4.8.5/lib
LIBS          = $(SUBLIBS)  -L/usr/local/Trolltech/Qt-4.8.5/lib -lQtSql -L/usr/local/Trolltech/Qt-4.8.5/lib -lQtGui -L/usr/X11R6/lib -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/local/Trolltech/Qt-4.8.5/bin/qmake
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

SOURCES       = ../WebmonServer/main.cpp \
		../WebmonServer/databaseConversation.cpp \
		../WebmonServer/gamemechanics.cpp \
		../WebmonServer/server.cpp \
		../WebmonServer/trainer.cpp \
		../WebmonServer/dialog.cpp moc_server.cpp \
		moc_trainer.cpp \
		moc_dialog.cpp
OBJECTS       = main.o \
		databaseConversation.o \
		gamemechanics.o \
		server.o \
		trainer.o \
		dialog.o \
		moc_server.o \
		moc_trainer.o \
		moc_dialog.o
DIST          = /usr/local/Trolltech/Qt-4.8.5/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/linux.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/gcc-base.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/gcc-base-unix.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/g++-base.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/g++-unix.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/debug.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/declarative_debug.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/shared.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/lex.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/include_source_dir.prf \
		../WebmonServer/WebmonServer.pro
QMAKE_TARGET  = WebmonServer
DESTDIR       = 
TARGET        = WebmonServer

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
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: ../WebmonServer/WebmonServer.pro  /usr/local/Trolltech/Qt-4.8.5/mkspecs/linux-g++/qmake.conf /usr/local/Trolltech/Qt-4.8.5/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/linux.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/gcc-base.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/gcc-base-unix.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/g++-base.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/g++-unix.conf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/debug.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/declarative_debug.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/shared.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/lex.prf \
		/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/include_source_dir.prf \
		/usr/local/Trolltech/Qt-4.8.5/lib/libQtSql.prl \
		/usr/local/Trolltech/Qt-4.8.5/lib/libQtCore.prl \
		/usr/local/Trolltech/Qt-4.8.5/lib/libQtGui.prl \
		/usr/local/Trolltech/Qt-4.8.5/lib/libQtNetwork.prl
	$(QMAKE) -spec /usr/local/Trolltech/Qt-4.8.5/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile ../WebmonServer/WebmonServer.pro
/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/unix.conf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/linux.conf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/gcc-base.conf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/gcc-base-unix.conf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/g++-base.conf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/common/g++-unix.conf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/qconfig.pri:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/modules/qt_webkit_version.pri:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/qt_functions.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/qt_config.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/exclusive_builds.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/default_pre.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/debug.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/default_post.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/declarative_debug.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/shared.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/warn_on.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/qt.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/unix/thread.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/moc.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/resources.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/uic.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/yacc.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/lex.prf:
/usr/local/Trolltech/Qt-4.8.5/mkspecs/features/include_source_dir.prf:
/usr/local/Trolltech/Qt-4.8.5/lib/libQtSql.prl:
/usr/local/Trolltech/Qt-4.8.5/lib/libQtCore.prl:
/usr/local/Trolltech/Qt-4.8.5/lib/libQtGui.prl:
/usr/local/Trolltech/Qt-4.8.5/lib/libQtNetwork.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/local/Trolltech/Qt-4.8.5/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile ../WebmonServer/WebmonServer.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/WebmonServer1.0.0 || $(MKDIR) .tmp/WebmonServer1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/WebmonServer1.0.0/ && $(COPY_FILE) --parents ../WebmonServer/databaseConversation.h ../WebmonServer/gamemechanics.h ../WebmonServer/server.h ../WebmonServer/trainer.h ../WebmonServer/constants.h ../WebmonServer/dialog.h .tmp/WebmonServer1.0.0/ && $(COPY_FILE) --parents ../WebmonServer/main.cpp ../WebmonServer/databaseConversation.cpp ../WebmonServer/gamemechanics.cpp ../WebmonServer/server.cpp ../WebmonServer/trainer.cpp ../WebmonServer/dialog.cpp .tmp/WebmonServer1.0.0/ && (cd `dirname .tmp/WebmonServer1.0.0` && $(TAR) WebmonServer1.0.0.tar WebmonServer1.0.0 && $(COMPRESS) WebmonServer1.0.0.tar) && $(MOVE) `dirname .tmp/WebmonServer1.0.0`/WebmonServer1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/WebmonServer1.0.0


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

compiler_moc_header_make_all: moc_server.cpp moc_trainer.cpp moc_dialog.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_server.cpp moc_trainer.cpp moc_dialog.cpp
moc_server.cpp: ../WebmonServer/server.h
	/usr/local/Trolltech/Qt-4.8.5/bin/moc $(DEFINES) $(INCPATH) ../WebmonServer/server.h -o moc_server.cpp

moc_trainer.cpp: ../WebmonServer/databaseConversation.h \
		../WebmonServer/constants.h \
		../WebmonServer/gamemechanics.h \
		../WebmonServer/trainer.h
	/usr/local/Trolltech/Qt-4.8.5/bin/moc $(DEFINES) $(INCPATH) ../WebmonServer/trainer.h -o moc_trainer.cpp

moc_dialog.cpp: ../WebmonServer/server.h \
		../WebmonServer/dialog.h
	/usr/local/Trolltech/Qt-4.8.5/bin/moc $(DEFINES) $(INCPATH) ../WebmonServer/dialog.h -o moc_dialog.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
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

main.o: ../WebmonServer/main.cpp ../WebmonServer/dialog.h \
		../WebmonServer/server.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o ../WebmonServer/main.cpp

databaseConversation.o: ../WebmonServer/databaseConversation.cpp ../WebmonServer/databaseConversation.h \
		../WebmonServer/constants.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o databaseConversation.o ../WebmonServer/databaseConversation.cpp

gamemechanics.o: ../WebmonServer/gamemechanics.cpp ../WebmonServer/gamemechanics.h \
		../WebmonServer/constants.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gamemechanics.o ../WebmonServer/gamemechanics.cpp

server.o: ../WebmonServer/server.cpp ../WebmonServer/server.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o server.o ../WebmonServer/server.cpp

trainer.o: ../WebmonServer/trainer.cpp ../WebmonServer/trainer.h \
		../WebmonServer/databaseConversation.h \
		../WebmonServer/constants.h \
		../WebmonServer/gamemechanics.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o trainer.o ../WebmonServer/trainer.cpp

dialog.o: ../WebmonServer/dialog.cpp ../WebmonServer/dialog.h \
		../WebmonServer/server.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dialog.o ../WebmonServer/dialog.cpp

moc_server.o: moc_server.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_server.o moc_server.cpp

moc_trainer.o: moc_trainer.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_trainer.o moc_trainer.cpp

moc_dialog.o: moc_dialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_dialog.o moc_dialog.cpp

####### Install

install_target: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/ || $(MKDIR) $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/ 
	-$(INSTALL_PROGRAM) "$(QMAKE_TARGET)" "$(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/$(QMAKE_TARGET)"

uninstall_target:  FORCE
	-$(DEL_FILE) "$(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/$(QMAKE_TARGET)"
	-$(DEL_DIR) $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/ 


install_sources: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/ || $(MKDIR) $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/ 
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/main.cpp $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/databaseConversation.cpp $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/gamemechanics.cpp $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/server.cpp $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/trainer.cpp $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/dialog.cpp $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/databaseConversation.h $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/gamemechanics.h $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/server.h $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/trainer.h $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/constants.h $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/dialog.h $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/WebmonServer.pro $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/


uninstall_sources:  FORCE
	-$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/main.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/databaseConversation.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/gamemechanics.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/server.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/trainer.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/dialog.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/databaseConversation.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/gamemechanics.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/server.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/trainer.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/constants.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/dialog.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/WebmonServer.pro
	-$(DEL_DIR) $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/ 


install_target: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/ || $(MKDIR) $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/ 
	-$(INSTALL_PROGRAM) "$(QMAKE_TARGET)" "$(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/$(QMAKE_TARGET)"

uninstall_target:  FORCE
	-$(DEL_FILE) "$(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/$(QMAKE_TARGET)" 
	 -$(DEL_FILE) "$(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/$(QMAKE_TARGET)"
	-$(DEL_DIR) $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/ 


install_sources: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/ || $(MKDIR) $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/ 
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/main.cpp $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/databaseConversation.cpp $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/gamemechanics.cpp $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/server.cpp $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/trainer.cpp $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/dialog.cpp $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/databaseConversation.h $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/gamemechanics.h $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/server.h $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/trainer.h $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/constants.h $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/dialog.h $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/
	-$(INSTALL_FILE) /home/priam93/Documents/WebMon/WebmonServer/WebmonServer/WebmonServer.pro $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/


uninstall_sources:  FORCE
	-$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/main.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/databaseConversation.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/gamemechanics.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/server.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/trainer.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/dialog.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/databaseConversation.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/gamemechanics.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/server.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/trainer.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/constants.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/dialog.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/WebmonServer.pro
	-$(DEL_DIR) $(INSTALL_ROOT)/usr/local/Trolltech/Qt-4.8.5/examples/xmlpatterns/schema/ 


install:  install_target install_sources install_target install_sources  FORCE

uninstall: uninstall_target uninstall_sources uninstall_target uninstall_sources   FORCE

FORCE:

