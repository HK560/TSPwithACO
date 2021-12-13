#include "aco.h"

ACO::ACO()
{
    init();
    this->locationNum=30;
}

ACO::ACO(int antSize, int cycletime, int PheromoneImportantValue, int HeFuntionImportValue, double PheromoneVolatilization)
{

//    Q_ASSERT(HeFuntionImportValue&&antSize&&cycletime&&PheromoneImportantValue&&PheromoneVolatilization);
    init();
    this->locationNum=30;
    this->cycletime=cycletime;
    this->HeFuntionImportValue=HeFuntionImportValue;
    this->antSize=antSize;
    this->PheromoneImportantValue=PheromoneImportantValue;
    this->PheromoneVolatilization=PheromoneVolatilization;
}

void ACO::start()
{
    int time=this->cycletime;
    while(time--){
        volatilePheromone();//信息素挥发
        for(int i=0;i<antSize;i++){//第i个蚂蚁
            qDebug()<<"______the"<<i<<"s ant";
            QVector<int>tmpAntPath;//存储该蚂蚁的路径
            QVector<bool>whetherExist(locationNum,false);//标记已走过的城市
            //生成随机起点城市
            int randomCityCode;
            do{
                randomCityCode=QRandomGenerator::system()->bounded(locationNum);
            }while(whetherExist.at(randomCityCode)==true);
            whetherExist[randomCityCode]=true;
            tmpAntPath.append(randomCityCode);//随机第一个点
            qDebug()<<"first pos:"<<randomCityCode;

            //对下一个城市的概率进行计算
            int nowCity=randomCityCode;
            for(int k=1;k<locationNum;k++){//第k个城市
                double sumProbability=0;//总概率
                QVector<double>nextCityProbabilityVector;//记录可以走的城市的概率
                QVector<bool>whetherFind(locationNum,false);//标记城市是否已经计算过概率
                QMap<double,int>probabilityToCityCodeMap;//记录概率对应的城市
                for(int cityCode=0;cityCode<locationNum;cityCode++){//计算能走的城市的概率
                    if(whetherExist[cityCode]==false&&whetherFind[cityCode]==false){//确保不是已经经过的城市也不是已经计算过的城市
                        whetherFind[cityCode]=true;//标记已经访问
                        double nextCityProbability=getProbability(nowCity,cityCode);//计算概率
                        nextCityProbabilityVector.append(nextCityProbability);//将概率添加到城市概率vector中
                        probabilityToCityCodeMap.insert(nextCityProbability,cityCode);//map里记录一下概率对应城市
                        sumProbability+=nextCityProbability;//总概率加上
                    }
                }
                qSort(nextCityProbabilityVector.begin(),nextCityProbabilityVector.end());//概率从小到大排序
                double eachProbaility=0;
                QMap<double,int>formatProbabilityToCityCodeMap;//记录归一化后的概率对应的城市
                for(auto i=nextCityProbabilityVector.begin();i!=nextCityProbabilityVector.end();i++){//对每个城市的概率
                    double probaility=*i;//取出概率
                    int cityCode=probabilityToCityCodeMap.value(probaility);//找到概率对应的城市
                    eachProbaility+=probaility/sumProbability;//概率归一化
                    formatProbabilityToCityCodeMap.insert(eachProbaility,cityCode);//记录归一化后概率对应城市
                    *i=eachProbaility;//重新给概率赋值
                }
                double randProbability=QRandomGenerator::system()->bounded(1.0);//生成个随机数0到1.0
                auto i=nextCityProbabilityVector.begin();
                for(;i!=nextCityProbabilityVector.end();i++){//从小到大找,若这个概率比随机的值大即返回,该概率对应的城市就是要去的下一个城市
                    if(randProbability<double(*i))
                        break;
                }


                nowCity=formatProbabilityToCityCodeMap.value(*i);//取出城市
                tmpAntPath.append(nowCity);//加到路径里
                whetherExist[nowCity]=true;//标记已经过
            }
            //计算路径长度



        }
    }




}

void ACO::init()
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
    Pheromone.fill(QVector<int>(30,1),30);
}

double ACO::getProbability(int pos1, int pos2)
{
    double distance=sqrt(qPow(qAbs((this->loc[pos1].getX())-(this->loc[pos2].getX())),2)+qPow(qAbs((this->loc[pos1].getY())-(this->loc[pos2].getY())),2));
    return qPow(Pheromone[pos1][pos2],PheromoneImportantValue)*qPow(distance,HeFuntionImportValue);
}

void ACO::volatilePheromone()
{
    Q_ASSERT(PheromoneVolatilization<1.0);
    for(auto i=Pheromone.begin();i!=Pheromone.end();i++){
        for(auto k=i->begin();k!=i->end();k++){
            *k=(*k)*(1-PheromoneVolatilization);
        }
    }
}
