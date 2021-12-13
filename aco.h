#ifndef ACO_H
#define ACO_H
#include"citymap.h"
#include<QVector>
#include<QRandomGenerator>
class ACO
{
public:
    ACO();
    ACO(int antSize,int cycletime,int PheromoneImportantValue,int HeFuntionImportValue,int PheromoneVolatilization);
    void antInit();
private:
    QVector<CityMap> loc;
    int locationNum;
    int antSize;
    int cycletime;
    int PheromoneImportantValue;
    int HeFuntionImportValue;
    int PheromoneVolatilization;
    QVector<QVector<int>>antPath;
};

#endif // ACO_H
