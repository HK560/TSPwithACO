#ifndef CITYMAP_H
#define CITYMAP_H


class CityMap
{
public:
    CityMap();
    CityMap(int code,int X,int Y);
    int getX();
    int getY();
    int getCode();
private:
    int X;
    int Y;
    int code;
    int cityNum;
};

#endif // CITYMAP_H
