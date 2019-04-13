#include <iostream>

int main() {

    //runtime assert
    int * mypointer = nullptr;
    assert(mypointer != nullptr);

    //compile time assert (c++11)
    static_assert(sizof(int) ==4);
    return 0;
}