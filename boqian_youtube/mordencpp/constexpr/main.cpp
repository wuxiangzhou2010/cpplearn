#include <iostream>
constexpr int A() { return 3; } /// force the computation to happen at compile time
constexpr int cubed(int x) { return x * x * x; }
int main()
{

    int arr[A() + 3]; // create an array of size 6

    // write faster program with constexpr

    int y = cubed(1789); // computed at compile time
    return 0;
}