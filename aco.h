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

    void start();//启动函数

    QLineSeries* getSeries();//获得数据点信息
    double getGlobalMinPathLength();
    QVector<int> getGlobalMinPath();
    double getPathLength(QVector<int>path);

    QVector<CityMap> loc;//存储城市位置信息
private:
    void init();

    int locationNum;
    int antSize;
    int cycletime;
    int PheromoneImportantValue;
    int HeFuntionImportValue;
    double PheromoneVolatilization;

    QVector<QVector<double>>Pheromone;//信息素
    QVector<QVector<int>>antPath;//蚂蚁路径
    QLineSeries* series=nullptr;
    double globalMinPathLength=99999;//DBL_MAX;
    QVector<int> globalMinPath;//全局最小路径

    double getProbability(int pos1,int pos2);
    void volatilePheromone();//信息素挥发
    void refreshPheromone(QVector<QVector<double>>newPheromone);//刷新信息素
    void debugPheromone();

signals:
    void sendPrograssValue(int value);//发送进度条进度数据
};

#endif // ACO_H
