#ifndef VIRTUALGLASSES_H
#define VIRTUALGLASSES_H

#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include <QtDebug>
#include "QDateTime"
#include <QVector3D>
#include "opencv2/opencv.hpp"
#include "facemetrics.h"

class VirtualGlasses: public QObject
{
    Q_OBJECT
public:
    VirtualGlasses();
    Q_INVOKABLE QDateTime getCurrentDateTime() const {
        return QDateTime::currentDateTime();
    }
    Q_INVOKABLE QString getTexture() const{
        return "../../../qtar2/face.jpg";
    }
    Q_INVOKABLE QImage getImage();
    Q_INVOKABLE QVector3D getTranslation(float scale);
    Q_INVOKABLE float getScale();
    Q_INVOKABLE float getXAngle();
    Q_INVOKABLE float getZAngle();
    Q_INVOKABLE float getYAngle();
    Q_INVOKABLE QVector3D getZOrigin(QVector3D scale3d);
    Q_INVOKABLE QVector3D getYOrigin(QVector3D scale3d);
    Q_INVOKABLE QVector3D getXOrigin(QVector3D scale3d);
    Q_INVOKABLE QVector3D getScale3d();
    QImage ipl2Qimg(IplImage* iplImg);


private:
    IplImage* iplImage;
    QImage qImage;
    void queryFrame();
    void startCamera();
    CvCapture *capture;
   FaceMetrics  *faceLandmarks;
    cv::Mat landmarks;
    std::vector<float> headpose;
};

#endif // VIRTUALGLASSES_H
