#ifndef ACOTHREAD_H
#define ACOTHREAD_H
#include<QThread>
#include"aco.h"
#include"citymap.h"
#include<QVector>
#include<QLineSeries>

class AcoThread:public QThread
{
    Q_OBJECT
public:
    AcoThread(QObject *parent=0);
protected:
    void run();
private:
    bool ready=false;
    int locationNum;
    int antSize;
    int cycletime;
    int PheromoneImportantValue;
    int HeFuntionImportValue;
    double PheromoneVolatilization;

    ACO* aco;
signals:
    void progressValue(int value);
    void minPath(QVector<int>path);
    void minPathLength(double pathLength);
    void sendSeries(QLineSeries* series);
public slots:
    void getProgressValue(int value);
    void getParameter(int antSize, int cycletime, int PheromoneImportantValue, int HeFuntionImportValue, double PheromoneVolatilization);
};

#endif // ACOTHREAD_H
