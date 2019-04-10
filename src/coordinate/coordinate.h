#ifndef __COORDINATE_H__
#define __COORDINATE_H__
#include <iostream>
using namespace std;
// 演示 friend 方法定义的使用方法，
// 1. 构造函数/带参数的构造函数
// 2. 析构函数
class Coordinate
{
  public:
    friend Coordinate &operator-(Coordinate &coor);
    friend Coordinate operator+(const Coordinate &, const Coordinate &);
    friend ostream &operator<<(ostream &out, const Coordinate &);
    Coordinate();
    Coordinate(int , int _y = 100); // 如果有两个参数， 则为默认构造函数, 调用的时候会有歧义
    Coordinate(const Coordinate &);
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