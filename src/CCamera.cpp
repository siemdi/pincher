#include "CCamera.h"

CCamera::CCamera()
{
    DEBUG("CCamera::CCamera()");
    imageCnt=0;
    capture=cvCreateCameraCapture(0);
    image = cvCreateImage(CvSize(800,600), IPL_DEPTH_8U, 3 );
}

IplImage* CCamera::GetImageFromCam()
{
    DEBUG("CCamera::GetImageFromCam()");

    image = cvQueryFrame( capture );
    return image;
}

