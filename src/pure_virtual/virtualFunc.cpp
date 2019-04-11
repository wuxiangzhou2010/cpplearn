#include <iostream>

class Base
{
  public:
    Base() {std::cout << "Base()" <<std::endl;}
    virtual ~Base() = 0;
};

Base::~Base()
    {std::cout<<"~Base()"<<std::endl;}

class Derived : public Base
{
  public:
    Derived() {std::cout<< "Derived()"<<std::endl;}
    ~Derived() {std::cout<<"~Derived()" <<std::endl;}

};

int main()
{
    Base *pb;
    pb = new Derived;
    delete pb;
}

//Base()
//Derived()
//~Derived()
//~Base()

//reference: https://www.cnblogs.com/burellow/archive/2011/05/25/2056506.html