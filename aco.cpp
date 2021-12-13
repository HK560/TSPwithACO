#include "aco.h"

ACO::ACO()
{
    loc.append(CityMap(1,87,7));
    loc.append(CityMap(2,91,38));
    loc.append(CityMap(3,83,46));
    loc.append(CityMap(4,71,44));
    loc.append(CityMap(5,64,60));
    loc.append(CityMap(6,68,58));
    loc.append(CityMap(7,83,69));
    loc.append(CityMap(8,87,76));
    loc.append(CityMap(9,74,78));
    loc.append(CityMap(10,71,71));
    loc.append(CityMap(11,58,62));
    loc.append(CityMap(12,54,62));
    loc.append(CityMap(13,51,67));
    loc.append(CityMap(14,37,84));
    loc.append(CityMap(15,41,94));
    loc.append(CityMap(16,2,99));
    loc.append(CityMap(17,7,64));
    loc.append(CityMap(18,22,60));
    loc.append(CityMap(19,25,62));
    loc.append(CityMap(20,18,54));
    loc.append(CityMap(21,4,50));
    loc.append(CityMap(22,13,40));
    loc.append(CityMap(23,18,40));
    loc.append(CityMap(24,24,42));
    loc.append(CityMap(25,25,38));
    loc.append(CityMap(26,41,26));
    loc.append(CityMap(27,45,35));
    loc.append(CityMap(28,44,35));
    loc.append(CityMap(29,58,35));
    loc.append(CityMap(30,62,32));
    this->locationNum=30;
}

ACO::ACO(int antSize, int cycletime, int PheromoneImportantValue, int HeFuntionImportValue, int PheromoneVolatilization)
{

    Q_ASSERT(HeFuntionImportValue&&antSize&&cycletime&&PheromoneImportantValue&&PheromoneVolatilization);
    loc.append(CityMap(1,87,7));
    loc.append(CityMap(2,91,38));
    loc.append(CityMap(3,83,46));
    loc.append(CityMap(4,71,44));
    loc.append(CityMap(5,64,60));
    loc.append(CityMap(6,68,58));
    loc.append(CityMap(7,83,69));
    loc.append(CityMap(8,87,76));
    loc.append(CityMap(9,74,78));
    loc.append(CityMap(10,71,71));
    loc.append(CityMap(11,58,62));
    loc.append(CityMap(12,54,62));
    loc.append(CityMap(13,51,67));
    loc.append(CityMap(14,37,84));
    loc.append(CityMap(15,41,94));
    loc.append(CityMap(16,2,99));
    loc.append(CityMap(17,7,64));
    loc.append(CityMap(18,22,60));
    loc.append(CityMap(19,25,62));
    loc.append(CityMap(20,18,54));
    loc.append(CityMap(21,4,50));
    loc.append(CityMap(22,13,40));
    loc.append(CityMap(23,18,40));
    loc.append(CityMap(24,24,42));
    loc.append(CityMap(25,25,38));
    loc.append(CityMap(26,41,26));
    loc.append(CityMap(27,45,35));
    loc.append(CityMap(28,44,35));
    loc.append(CityMap(29,58,35));
    loc.append(CityMap(30,62,32));
    this->locationNum=30;
    this->cycletime=cycletime;
    this->HeFuntionImportValue=HeFuntionImportValue;
    this->antSize=antSize;
    this->PheromoneImportantValue=PheromoneImportantValue;
    this->PheromoneVolatilization=PheromoneVolatilization;
}

void ACO::antInit()
{
    for(int i=0;i<antSize;i++){
        QVector<int>tmpAntPath;
        QVector<bool>whetherExist(locationNum,false);//标记已走过的城市
        for(int k=0;k<locationNum;k++){
            int randomCityCode;
            do{
                randomCityCode=QRandomGenerator::system()->bounded(locationNum);
            }while(whetherExist.at(randomCityCode)==true);
            whetherExist[randomCityCode]=true;
            tmpAntPath.append(randomCityCode);
        }


    }


}
