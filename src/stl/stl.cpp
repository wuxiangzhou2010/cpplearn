#include <iostream>
#include <vector>
#include <list>
#include <map>
// 演示STL  vector, list， map 的使用
//using namespace std;
void printline();
int main(void)
{
    printline();
    //演示vector的使用
    std::cout << " 1. demonstrate Vector:  " << std::endl;

    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(4);
    vec.push_back(6);
    vec.pop_back();

    std::cout << "vector size " << vec.size() << std::endl;

    std::cout << "iterate using traditional i ";
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    //std::vector<int>::iterator itor= vec.begin();
    std::cout << "iterate vector using iterator " << std::endl;
    auto itor1 = vec.begin();
    std::cout << "vec.begin is: " << *itor1 << std::endl;
    std::cout << " iterate vector: ";
    for (; itor1 != vec.end(); itor1++)
    {
        std::cout << *itor1 << " ";
    }
    std::cout << std::endl;
    std::cout << "vec.front() " << vec.front() << std::endl; // first element
    std::cout << "vec.back() " << vec.back() << std::endl;   // last element

    printline();
    //演示 list的使用
    std::cout << "2. demonstrate List:" << std::endl;
    std::list<int> list1;
    list1.push_back(1);
    list1.push_back(4);
    list1.push_back(7);

    //std::list<int>::iterator itor_list = list1.begin();
    auto itor_list = list1.begin();
    for (; itor_list != list1.end(); itor_list++)
    {
        std::cout << *itor_list << std::endl;
    }

    printline();
    // 演示map的使用
    std::cout << " 3. demonstrate map  " << std::endl;

    std::map<int, std::string> m;
    std::pair<int, std::string> p1(3, "hello"); //std::pair<T,T>
    std::pair<int, std::string> p2(4, "world");

    m.insert(p1); // insert()
    m.insert(p2);
    std::cout << "get map value using key m[kay]";
    std::cout << m[3] << std::endl;
    std::cout << m[4] << std::endl;
    std::cout << "iterate the map ";
    // map<int, string>::iterator itor = m.begin(); // 使用一般迭代器
    auto itor_map = m.begin(); // 使用C++ 11 auto
    for (; itor_map != m.end(); itor_map++)
    {
        std::cout << "key: " << (*itor_map).first << " value: " << (*itor_map).second << std::endl; //fist and second
    }
}

void printline()
{
    for (int i = 0; i < 50; i++)
    {
        std::cout << "**";
    }
    std::cout << std::endl;
}