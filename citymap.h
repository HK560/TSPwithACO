#ifndef CITYMAP_H
#define CITYMAP_H


class CityMap
{
public:
    CityMap();
    CityMap(int code,int X,int Y);
//    void qdebugLocation();
    int getX();
    int getY();
    int getCode();
//    void setCityNum(int num);
private:
    int X;
    int Y;
    int code;
    int cityNum;

};

#endif // CITYMAP_H
