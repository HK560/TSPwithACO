#include "citymap.h"

CityMap::CityMap()
{

}

CityMap::CityMap(int code, int X, int Y)
{
    this->X=X;
    this->Y=Y;
    this->code=code;
}

int CityMap::getX()
{
    return this->X;
}

int CityMap::getY()
{
    return this->Y;
}

int CityMap::getCode()
{
    return this->code;
}

//void CityMap::setCityNum(int num)
//{
//    this->cityNum=num;
//}
