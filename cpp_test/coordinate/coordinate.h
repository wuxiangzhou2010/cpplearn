#ifndef __COORDINATE_H__
#define __COORDINATE_H__
#include <iostream>
using namespace std;
// 演示 类份文件类外定义的使用方法，
// 1. 构造函数， 带参数的构造函数
// 2. 析构函数
class Coordinate
{
  public:
    friend Coordinate &operator-(Coordinate &coor);
    friend Coordinate operator+(const Coordinate &, const Coordinate &);
    friend ostream &operator<<(ostream &out, const Coordinate &);
    Coordinate();
    Coordinate(int, int);
    ~Coordinate();
    int getX();
    int getY();
    //Coordinate& operator-();
    Coordinate &operator++();
    Coordinate operator++(int);
    //Coordinate operator+(const Coordinate&);
    int operator[](int);

  private:
    int m_iX;
    int m_iY;
};
#endif