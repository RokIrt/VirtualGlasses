#include "facemetrics.h"

bool compareRect(cv::Rect r1, cv::Rect r2) { return r1.height < r2.height; }

FaceMetrics::FaceMetrics(QString modelsPath="intraface/models")
{
       xRot=0;
        yRot=0;
        zRot=0;

    char detectionModel[] = "../../intraface/models/DetectionModel-v1.5.bin";
    char trackingModel[]  = "../../intraface/models/TrackingModel-v1.10.bin";
    string faceDetectionModel("../../intraface/models/haarcascade_frontalface_alt2.xml");

    xxd=new  INTRAFACE::XXDescriptor(4);
    fa=new INTRAFACE::FaceAlignment(detectionModel, trackingModel, xxd,cv::Rect_<double>(0,0,1,1));

    if (!fa->Initialized()) {
        cerr << "FaceAlignment cannot be initialized." << endl;
    }
        // load OpenCV face detector model
    face_cascade;
    if( !face_cascade.load( faceDetectionModel ) )
    {
        cerr << "Error loading face detection model." << endl;

    }
    float score=0;
   /* cv::Mat frame=cv::imread("c:\\1.jpg");
    if (fa->Detect(frame,cv::Rect(100,100,200,200),X0,score) != INTRAFACE::IF_OK)
        qDebug() << "fa->Detect error" << endl;*/
    isDetect = true;

}

IplImage *FaceMetrics::detect(IplImage* iplframe)
{
    if (!fa->Initialized()) {
            cerr << "FaceAlignment cannot be initialized." << endl;

        }

    cv::Mat frame(iplframe);
    vector<cv::Rect> faces;

    float score=0;
    double notFace = 0.3;
    if (isDetect)
    {
        // face detection
        vector<cv::Rect> faces;
        face_cascade.detectMultiScale(frame, faces, 1.2, 2, 0, cv::Size(50, 50));
        if(faces.size()>0)
        if (fa->Detect(frame,*max_element(faces.begin(),faces.end(),compareRect),X0,score) != INTRAFACE::IF_OK)
                cerr << "FaceAlignment detector error." << endl;
        //fa->Detect(frame,*max_element(faces.begin(),faces.end(),compareRect),X0,score);
        isDetect = false;
    }else
    {
        // facial feature tracking
        //if (fa->Track(frame,X0,X,score) != INTRAFACE::IF_OK)
        fa->Track(frame,X0,X,score);
        X0 = X;
    }
    if (score < notFace){ // detected face is not reliable
        isDetect = true;

    }
    else
    {
        INTRAFACE::HeadPose hp;
        fa->EstimateHeadPose(X0,hp);
        drawPose(frame, hp.rot, 50);
        xRot=hp.angles[0];
        yRot=hp.angles[1];
        zRot=hp.angles[2];
        // plot facial landmarks
        for (int i = 0 ; i < X0.cols ; i++)
            if(i==25 || i==22)
            {

                cv::circle(frame,cv::Point((int)X0.at<float>(0,i), (int)X0.at<float>(1,i)), 1, cv::Scalar(0,255,0), -1);
                cv::putText(frame, std::to_string(i), cv::Point((int)X0.at<float>(0,i), (int)X0.at<float>(1,i)),1, 1, cv::Scalar::all(255), 1,8);
        }

    }

    //IplImage* image2=cvCloneImage(&(IplImage)frame);
    return iplframe;

}

void FaceMetrics::drawPose(cv::Mat& img, const cv::Mat& rot, float lineL)
{
    int loc[2] = {70, 70};
    int thickness = 2;
    int lineType  = 8;

    cv::Mat P = (cv::Mat_<float>(3,4) <<
        0, lineL, 0,  0,
        0, 0, -lineL, 0,
        0, 0, 0, -lineL);
    P = rot.rowRange(0,2)*P;
    P.row(0) += loc[0];
    P.row(1) += loc[1];
    cv::Point p0(P.at<float>(0,0),P.at<float>(1,0));

    line(img, p0, cv::Point(P.at<float>(0,1),P.at<float>(1,1)), cv::Scalar( 255, 0, 0 ), thickness, lineType);
    line(img, p0, cv::Point(P.at<float>(0,2),P.at<float>(1,2)), cv::Scalar( 0, 255, 0 ), thickness, lineType);
    line(img, p0, cv::Point(P.at<float>(0,3),P.at<float>(1,3)), cv::Scalar( 0, 0, 255 ), thickness, lineType);
}
