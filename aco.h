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
private:
    QVector<CityMap> loc;
    void init();
    int locationNum;
    double getPathLength(QVector<int>path);
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
    QLineSeries* series;
    void debugPheromone();
};

#endif // ACO_H
