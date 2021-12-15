#include "acothread.h"

AcoThread::AcoThread(QObject *parent):QThread(parent)
{

}

void AcoThread::run()
{
    Q_ASSERT(ready);

    aco=new ACO( antSize,  cycletime,  PheromoneImportantValue,  HeFuntionImportValue,  PheromoneVolatilization);
    connect(aco,SIGNAL(sendPrograssValue(int)),this,SLOT(getProgressValue(int)));

    aco->start();
    emit sendSeries(aco->getSeries());
    QVector<int>pathTmp=aco->getGlobalMinPath();
    double pathLengthTmp=aco->getGlobalMinPathLength();
    emit minPath(pathTmp);
    emit minPathLength(pathLengthTmp);
}

void AcoThread::getProgressValue(int value)
{
    int sendValue=((value+1)/(double)cycletime)*100;
    qDebug()<<"orgrecvalue"<<value<<"sendValue:"<<sendValue;
    emit progressValue(sendValue);
}

void AcoThread::getParameter(int antSize, int cycletime, int PheromoneImportantValue, int HeFuntionImportValue, double PheromoneVolatilization)
{
    this->locationNum=30;
    this->cycletime=cycletime;
    this->HeFuntionImportValue=HeFuntionImportValue;
    this->antSize=antSize;
    this->PheromoneImportantValue=PheromoneImportantValue;
    this->PheromoneVolatilization=PheromoneVolatilization;
    this->ready=true;
}
