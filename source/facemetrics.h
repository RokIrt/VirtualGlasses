#ifndef FACEMETRICS_H
#define FACEMETRICS_H
#include <QString>
#include <opencv2/core/core.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include "intraface/FaceAlignment.h"
#include "intraface/XXDescriptor.h"
#include <QDebug>


using namespace std;
class FaceMetrics
{
public:
    FaceMetrics(QString modelsPath);
    IplImage* detect(IplImage* frame);
    cv::Mat X0;
    float xRot,yRot,zRot;
    bool isDetect;
private:
    cv::Mat X;
   cv::CascadeClassifier face_cascade;
   INTRAFACE::XXDescriptor *xxd;
   INTRAFACE::FaceAlignment *fa;
   void drawPose(cv::Mat& img, const cv::Mat& rot, float lineL);
};
#endif // FACEMETRICS_H
