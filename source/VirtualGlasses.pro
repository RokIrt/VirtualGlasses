QT += opengl 3d

## Qt3D and QtQuick3D modules
CONFIG += qt3d qt3dquick

OPENCV_PATH = D:/opencv2/build/
INTRAFACE_PATH= ../intraface
INTRAFACE_PATH_LIB= D:/github/VirtualGlasses/intraface

LIBS_PATH = "$$OPENCV_PATH/lib" #project compiled using Visual C++ 2010 32bit compiler

    CONFIG(debug, debug|release) {
    LIBS     += -L$$LIBS_PATH/Debug \
                -lopencv_core248d \
                -lopencv_highgui248d\
                -lopencv_objdetect248d\
                -lopencv_imgproc248d

    }

    CONFIG(release, debug|release) {
    LIBS     += -L$$LIBS_PATH/Release \
                -lopencv_core248 \
                -lopencv_highgui248 \
                -lopencv_objdetect248 \
                -lopencv_imgproc248
    }




INCLUDEPATH += $$OPENCV_PATH/install/include #core module

##INFRAFACE
INCLUDEPATH += $$INTRAFACE_PATH/include

CONFIG(release, debug|release) {
    LIBS     += -L$$INTRAFACE_PATH_LIB \
            -lIntraFaceDLL
}
CONFIG(debug, debug|release) {
    LIBS     += -L$$INTRAFACE_PATH_LIB \
            -lIntraFaceDLLd
}

# Add more folders to ship with the application, here
folder_01.source = qml/VirtualGlasses
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =




# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
   virtualglasses.cpp \
   facemetrics.cpp

RESOURCES += \
   res.qrc

OTHER_FILES +=

HEADERS += \
   virtualglasses.h \
  facemetrics.h
