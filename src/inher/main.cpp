//
// Created by wuxiang on 4/10/2019.
//

#include <iostream>
#include "person.h"
#include "Worker.h"

int personTest()
{
    Person p0("test"); //带参数构造函数
    Person p1 = p0;    // 拷贝构造函数
    std::cout << p1.getName() << "  " << p1.getAge() << std::endl;
    Person *p2 = new Person(); // 默认构造函数
    std::cout << p2->getAge() << "  " << p2->getName() << std::endl;
    //    std::cout<< p2->m_strName<<std::endl; //protected member
    delete p2;
    p2 = NULL;
    return 0;
}
int workerTest()
{
    Worker w0;
    Worker *w1 = new Worker();
    w1->work(3);
    delete w1;
    w1 = NULL;
    return 0;
}

int main()
{
    personTest();
    //    workerTest();
    return 0;
}