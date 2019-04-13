#include <iostream>

class dog{
public:
    void doOtherThings(){}
    dog()
    {
        std::cout<< "dog()" << std::endl;
    };
    dog(int a):dog()
    {

        doOtherThings();
    }
};
int main() {

    dog *d = new dog(1);
    return 0;
}