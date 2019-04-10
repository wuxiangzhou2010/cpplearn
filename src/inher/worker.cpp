//
// Created by wuxiang on 4/10/2019.
//

#include "Worker.h"
#include <iostream>
using namespace std;

Worker::Worker() : m_iSalary(0)
{
    cout << "Worker()" << endl;
}
Worker::Worker(const Worker &)
{
    cout << "Worker(const Worker &)" << endl;
};
Worker::~Worker()
{
    cout << "~Worker()" << endl;
}
int Worker::getSalary()
{
    return m_iSalary;
}
void Worker::work(int _salary)
{
    m_iSalary += _salary;
}