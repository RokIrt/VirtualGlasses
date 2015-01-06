#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "QQmlContext"
#include "virtualglasses.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QtQuick2ApplicationViewer viewer;
    VirtualGlasses data;
    viewer.rootContext()->setContextProperty("VirtualGlasses", &data);
    viewer.setMainQmlFile(QStringLiteral("qml/VirtualGlasses/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
