#ifndef CFINITESTATEMACHINE_H
#define CFINITESTATEMACHINE_H

#include <QElapsedTimer>
#include <QtSerialPort/QSerialPort>
#include <QTextStream>

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>

#include "CCamera.h"
#include "CErrorHandler.h"

class CFiniteStateMachine : public CErrorHandler
{
public:
    CFiniteStateMachine();
    CCamera         *camera;
    void            Start();
private:
    enum            states {Com, Camera, Math, Logging, Idle} EState;
    unsigned int    m_pause;
    unsigned int    m_time;
    unsigned int    m_elapsed;
    QElapsedTimer   m_timer;
    char            str[11];
};

#endif // CFINITESTATEMACHINE_H
