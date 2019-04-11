#include <iostream>

/* 演示模板类的使用
 * 1. 所有成员函数的类外定义都要加上template<typename T, int  kSize, int kVal>
*/
template <typename T, int kSize, int kVal>
class MyArray
{
  public:
    MyArray();
    ~MyArray();

    void display();

  private:
    T *m_pArr;
};

template <typename T, int kSize, int kVal>
MyArray<T, kSize, kVal>::MyArray()
{
    m_pArr = new T[kSize];
    for (int i = 0; i < kSize; i++)
    {
        m_pArr[i] = kVal;
    }
}
template <typename T, int kSize, int kVal>
MyArray<T, kSize, kVal>::~MyArray()
{
    delete[] m_pArr; // 数组指针删除方式
    m_pArr = NULL;
}

template <typename T, int kSize, int kVal>
void MyArray<T, kSize, kVal>::display()
{
    for (int i = 0; i < kSize; i++)
    {
        std::cout << m_pArr[i] << std::endl;
    }
}