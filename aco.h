#ifndef ACO_H
#define ACO_H
#include"citymap.h"
#include<QVector>
#include<QRandomGenerator>
#include<QtMath>
#include<QtAlgorithms>
#include<QMap>
#include<QDebug>
class ACO
{
public:
    ACO();
    ACO(int antSize,int cycletime,int PheromoneImportantValue,int HeFuntionImportValue,double PheromoneVolatilization);
    void start();
private:
    QVector<CityMap> loc;
    void init();
    int locationNum;
    int antSize;
    int cycletime;
    int PheromoneImportantValue;
    int HeFuntionImportValue;
    double PheromoneVolatilization;
    double getProbability(int pos1,int pos2);
    void volatilePheromone();
    QVector<QVector<int>>Pheromone;
    QVector<QVector<int>>antPath;
};

#endif // ACO_H
