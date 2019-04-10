//
// Created by wuxiang on 4/10/2019.
//

#ifndef TEST_WORKER_H
#define TEST_WORKER_H

#include "person.h"

class Worker : private Person
{

  public:
    Worker();
    Worker(const Worker &);
    ~Worker();
    int getSalary();
    void work(int _salary);

  private:
    int m_iSalary;
};

#endif //TEST_WORKER_H
