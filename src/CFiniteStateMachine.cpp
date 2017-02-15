#include "CFiniteStateMachine.h"

CFiniteStateMachine::CFiniteStateMachine(): CErrorHandler()
  , EState(Camera)
  , m_pause(100)
{
    DEBUG("CFiniteStateMachine::CFiniteStateMachine()");
    camera = new CCamera();
}

void CFiniteStateMachine::Start()
{
    DEBUG("CFiniteStateMachine::Start()");
    m_timer.start();
    m_time = 1;
    m_time = m_timer.elapsed();

    while(true)
    {
        switch (EState)
        {
        case Com:
        {
            EState=Camera;
            break;
        }
        case Camera:
        {
            m_elapsed = m_timer.elapsed() - m_time;
            sprintf(str, "%d", m_elapsed);
            FATAL(str);
            m_time = m_timer.elapsed();
            cvShowImage("IM", camera->GetImageFromCam());

            EState=Math;
            break;
        }
        case Math:
        {
            EState=Logging;
            break;
        }
        case Logging:
        {
            EState=Idle;
            break;
        }
        case Idle:
        {
            cvWaitKey(m_pause);
            EState=Com;
            break;
        }
        }
    }
}
