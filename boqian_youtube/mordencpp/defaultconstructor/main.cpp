#include <iostream>
class dog
{
public:
    dog(int);
    dog() = default;
};
int main()
{
    dog d1;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}