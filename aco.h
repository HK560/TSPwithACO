#ifndef ACO_H
#define ACO_H
#include"citymap.h"
#include<QVector>
#include<QRandomGenerator>
#include<QtMath>
#include<QtAlgorithms>
#include<QMap>
#include<QDebug>
#include<QDialog>
#include<QMessageBox>
#include <QChartView>
#include<QChart>
#include <QLineSeries>
#include <QValueAxis>
#include <QtCharts>

#define Q 1
using namespace QtCharts;

class ACO:public QObject
{
        Q_OBJECT
public:
    ACO();
    ACO(int antSize,int cycletime,int PheromoneImportantValue,int HeFuntionImportValue,double PheromoneVolatilization);
    void start();
    QLineSeries* getSeries();
    double getGlobalMinPathLength();
    QVector<int> getGlobalMinPath();
    QVector<CityMap> loc;
    double getPathLength(QVector<int>path);
private:

    void init();
    int locationNum;

    int antSize;
    int cycletime;
    int PheromoneImportantValue;
    int HeFuntionImportValue;
    double PheromoneVolatilization;
    double getProbability(int pos1,int pos2);
    void volatilePheromone();
    QVector<QVector<double>>Pheromone;//信息素
    void refreshPheromone(QVector<QVector<double>>newPheromone);
    QVector<QVector<int>>antPath;
    QLineSeries* series=nullptr;
    void debugPheromone();
    double globalMinPathLength=__DBL_MAX__;
    QVector<int> globalMinPath;
signals:
    void sendPrograssValue(int value);
};

#endif // ACO_H
