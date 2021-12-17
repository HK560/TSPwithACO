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
    void run();//线程执行函数
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
    void progressValue(int value);//进度条进度信号
    void minPath(QVector<int>path);//最小路径信号
    void minPathLength(double pathLength);
    void sendSeries(QLineSeries* series);
public slots:
    void getProgressValue(int value);
    void getParameter(int antSize, int cycletime, int PheromoneImportantValue, int HeFuntionImportValue, double PheromoneVolatilization);
};

#endif // ACOTHREAD_H
