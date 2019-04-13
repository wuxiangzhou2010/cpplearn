#include <iostream>
#include <vector>

template <typename func>
void filter(func f, std::vector<int> arr)
{
    for (auto i : arr)
    {
        if (f(i))
            std::cout << i << " ";
    }
    std::cout << std::endl;
}
int main()
{

    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    filter([](int x) { return (x > 3); }, v);
    filter([](int x) { return (x > 2 && x < 5); }, v);
    int y = 4;
    filter([&](int x) { return (x > y); }, v);

    return 0;
}