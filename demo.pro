#-------------------------------------------------
#
# Project created by QtCreator 2017-04-05T08:39:17
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = player
TEMPLATE = app


SOURCES += main.cpp\
    yuvrender.cpp \
    yuvfileplayer.cpp \
    common_routine.cpp \
    yuvalg.cpp \
    alg/cascadedetect.cpp \
    alg/m_arith.cpp \
    alg/VC_DSP_TRANSFORM.cpp \
    load-cfg.cpp

HEADERS  +=  \
    yuvrender.h \
    yuvfileplayer.h \
    common_routine.h \
    g_define.h \
    yuvalg.h \
    alg/cascade_day_xml.h \
    alg/cascade_dusk_xml.h \
    alg/cascade_night_xml.h \
    alg/cascade_xml.h \
    alg/cascadedetect.h \
    alg/DSPARMProto.h \
    alg/m_arith.h \
    load-cfg.h

CVPATH=/root/repo-github/libs/third-party/opencv/
unix:CVNAME=opencv-linux-x86
win32:CVNAME=opencv-vs2013-x86
win32:CONFIG(release, debug|release): LIBS += -L$$CVPATH/$$CVNAME/lib/ -lopencv_core245
else:win32:CONFIG(debug, debug|release): LIBS += -L$$CVPATH/$$CVNAME/lib/ -lopencv_core245
else:unix: LIBS += -L$$CVPATH/$$CVNAME/lib/ -lopencv_core

INCLUDEPATH += $$CVPATH/$$CVNAME/include
DEPENDPATH += $$CVPATH/$$CVNAME/include

win32:CONFIG(release, debug|release): LIBS += -L$$CVPATH/$$CVNAME/lib/ -lopencv_highgui245
else:win32:CONFIG(debug, debug|release): LIBS += -L$$CVPATH/$$CVNAME/lib/ -lopencv_highgui245
else:unix: LIBS += -L$$CVPATH/$$CVNAME/lib/ -lopencv_highgui

INCLUDEPATH += $$CVPATH/$$CVNAME/include
DEPENDPATH += $$CVPATH/$$CVNAME/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/res/linux32/win32/lib/  -lopencv_imgproc245
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/res/linux32/win32/lib/  -lopencv_imgproc245
else:unix: LIBS += -L$$CVPATH/$$CVNAME/lib/ -lopencv_imgproc

INCLUDEPATH += $$CVPATH/$$CVNAME/include
DEPENDPATH += $$CVPATH/$$CVNAME/include

win32:CONFIG(release, debug|release): LIBS += -L$$CVPATH/$$CVNAME/lib/ -lopencv_ml245
else:win32:CONFIG(debug, debug|release): LIBS += -L$$CVPATH/$$CVNAME/lib/  -lopencv_ml245
else:unix: LIBS += -L$$CVPATH/$$CVNAME/lib/ -lopencv_ml

INCLUDEPATH += $$CVPATH/$$CVNAME/include
DEPENDPATH += $$CVPATH/$$CVNAME/include

win32:CONFIG(release, debug|release): LIBS += -L$$CVPATH/$$CVNAME/lib/  -lopencv_video245
else:win32:CONFIG(debug, debug|release): LIBS += -L$$CVPATH/$$CVNAME/lib/  -lopencv_video245
else:unix: LIBS += -L$$CVPATH/$$CVNAME/lib/ -lopencv_video

INCLUDEPATH += $$CVPATH/$$CVNAME/include
DEPENDPATH += $$CVPATH/$$CVNAME/include
