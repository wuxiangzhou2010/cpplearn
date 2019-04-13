#include <iostream>

// 演示子类中显式重载父类中的方法
class dog
{
    virtual void A();
    virtual void B() const;
    void C();
};

class yellowdog : public dog
{
    void A(int) override;
    void B() override;
    void C() override;
};
int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}