#ifndef CCAMERA_H
#define CCAMERA_H
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "CErrorHandler.h"
class CCamera : public CErrorHandler
{
public:
    CCamera();
    IplImage *GetImageFromCam();

private:
    CvCapture               *capture;
    IplImage                *image;
    CvSize                  mySize;
    int                     imageCnt;
};

#endif // CCAMERA_H
