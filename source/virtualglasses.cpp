#include "virtualglasses.h"


VirtualGlasses::VirtualGlasses(){
    VirtualGlasses::startCamera();
    faceLandmarks=new FaceMetrics("");

}

void VirtualGlasses::queryFrame(){
    iplImage = cvQueryFrame(capture);
    cvFlip (iplImage, iplImage, 1);
    faceLandmarks->detect(iplImage);
    qImage = VirtualGlasses::ipl2Qimg(iplImage);
    //emit newFrame();
}
void VirtualGlasses::startCamera(){
   /* std::string str="c:\\bigb.mpg";
    const char * c = str.c_str();
    capture =cvCreateFileCapture(c);
*/
    capture = cvCreateCameraCapture(0);
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, 800 );
    cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, 600);
}
QImage VirtualGlasses::getImage(){
    VirtualGlasses::queryFrame();
    return qImage;
}
float VirtualGlasses::getScale(){
    float x=(float)faceLandmarks->X0.at<float>(0,25);
    float x2=(float)faceLandmarks->X0.at<float>(0,22);
    float scale=-(x2-x);
    scale/=cos(faceLandmarks->yRot*0.0174532);
    scale/=cos(faceLandmarks->xRot*0.0174532);
    scale=floor(scale/2)*2;
    scale/=70;
    //qDebug() << QString::number(faceLandmarks->xRot)<< endl;
    if(faceLandmarks->isDetect)
        scale=0;

    return scale;
}
QVector3D VirtualGlasses::getScale3d(){
    float scale=0.025;
    if(faceLandmarks->X0.cols>30){
        float x=(float)faceLandmarks->X0.at<float>(0,25);
        float x2=(float)faceLandmarks->X0.at<float>(0,22);
        scale=-(x2-x);
        scale/=cos(faceLandmarks->yRot*0.0174532);
        scale/=cos(faceLandmarks->xRot*0.0174532);
        scale=floor(scale/2)*2;
        scale/=70;
        qDebug() << "xRot" << QString::number(faceLandmarks->xRot)<< endl;
    }
    if(faceLandmarks->isDetect)
        scale=0;

      QVector3D a(scale,scale,scale);
    return a;
}

QVector3D VirtualGlasses::getTranslation(float scale){
    float x=0.000;
    float y=0.000;
    float x2=0.000;
    float y2=0.000;
    float centerX=0;
    float centerY=0;
    if(faceLandmarks->X0.cols>30){
        x=(float)faceLandmarks->X0.at<float>(0,22);
        x2=(float)faceLandmarks->X0.at<float>(0,25);
        y=(float)faceLandmarks->X0.at<float>(1,22);
        y2=(float)faceLandmarks->X0.at<float>(1,25);
        centerX=(x+(x2-x)/2);
        centerY=-((y+(y2-y)/2));
        centerX=(centerX-400)/200;
        centerY=(centerY+250)/200;

    }
     qDebug() << QString::number( scale, 'f', 6 );
     //qDebug() << QString::number( centerY*200, 'f', 6 );

   //QVector3D a(centerX,centerY,0);
    QVector3D a(centerX,centerY,0);
   return a;
}
float VirtualGlasses::getXAngle(){
    float x=0;
    x=faceLandmarks->xRot;
   // qDebug() << QString::number( x, 'f', 6 );
    return x;
}

QVector3D VirtualGlasses::getZOrigin(QVector3D scale3d){
    float scale=scale3d.x();
   // float origin=0.7*scale/0.915;
    float origin=0.7*scale;

    return QVector3D(-1,0,origin);
}
QVector3D VirtualGlasses::getYOrigin(QVector3D scale3d){
     float scale=scale3d.x();
     float origin=0.7*scale/1.00;
     return QVector3D(0,0,origin);
}

QVector3D VirtualGlasses::getXOrigin(QVector3D scale3d)
{
    float scale=scale3d.x();
    float origin=0.7*scale;
    //float origin=0;
    qDebug() << QString::number(scale)<< endl;
    return QVector3D(0,0,origin);
}

float VirtualGlasses::getYAngle(){
    return faceLandmarks->yRot;

}

float VirtualGlasses::getZAngle(){
    return -faceLandmarks->zRot;

}

QImage VirtualGlasses::ipl2Qimg(IplImage* iplImg){
    int h = iplImg->height;
    int w = iplImg->width;
    int channels = iplImg->nChannels;
    QImage qimg(w, h, QImage::Format_ARGB32);
    char *data = iplImg->imageData;

    for (int y = 0; y < h; y++, data += iplImg->widthStep)
    {
        for (int x = 0; x < w; x++)
        {
            char r, g, b, a = 0;
            if (channels == 1)
            {
                r = data[x * channels];
                g = data[x * channels];
                b = data[x * channels];
            }
            else if (channels == 3 || channels == 4)
            {
                r = data[x * channels + 2];
                g = data[x * channels + 1];
                b = data[x * channels];
            }

            if (channels == 4)
            {
                a = data[x * channels + 3];
                qimg.setPixel(x, y, qRgba(r, g, b, a));
            }
            else
            {
                qimg.setPixel(x, y, qRgb(r, g, b));
            }
        }
    } return qimg;
}

