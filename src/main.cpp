#include <QCoreApplication>
#include "CFiniteStateMachine.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CFiniteStateMachine *fsm = new CFiniteStateMachine;
    fsm->Start();
    return a.exec();
}
