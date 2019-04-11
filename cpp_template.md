# [C++ 远征之模板篇](https://www.imooc.com/learn/477)

## 2-1 友元函数和友元类

- 友元函数

  - 友元全局函数
  - 友元成员函数

* 友元类

note:

- 友元关系不可传递
- 友元关系的单向性
- 友元声明的形式及数量不受限制

note: 定向暴露，不建议使用，不符合封装性

## 3. static

静态成员变量和静态成员函数不属于实例， 而属于类， 没有 this 指针

- 静态数据成员必须在类外单独初始化， 不能够写到构造函数中去
- 静态成员函数不能调用非静态成员函数和非静态数据成员
- 静态数据成员只有一份，不依赖对象而存在， 不占用对象空间
- 静态成员函数不能用 const 修饰， 因为 const 本身修饰的是 this 指针， 对静态函数而言， 不传入 this 指针

## C++中的函数重载

在同一个作用域内，可以声明几个功能类似的同名函数，但是这些同名函数的形式参数（指参数的个数、类型或者顺序）必须不同。

## 4. 运算符重载

- 概念： 给原有运算符赋予新功能

- 本质是函数重载
- 关键字 operator

- 可重载运算符/不可重载运算符

- 一元运算符重载：常用`-` `++`

- `-`负号的重载：

  - 成员函数重载

    ```cpp
    //成员函数重载 return *this
    Coordinate& Coordinate::operator-()
    {
        m_iX = -m_iX;
        m_iY= -m_iY;
        return *this;
    }

    //调用的时候相当于调用重载函数
    //Coordinate coor1;
    //-coor1; // coor1.operator-();
    ```

  - 友元全局函数重载 `return *this`

    ```cpp
    //friend Coordinate& operator-(Coordinate &coor)
    //-coor1; //operator-(coor1);
    Coordinate& operator-()(Coordinate &coor)
    {
        coor.m_iX=-coor.m_iY;
        coor.m_iY= - coor.m_iY;
        return *this;
    }
    ```

- ++ 符号重载

  - 前置++

    ```cpp
    // Coordinate& Coordinate::operator++();
    // ++coor1; // coor1.operator++();
    Coordinate& Coordinate::operator++()
    {
        m_iX++;
        m_iY++;
        return *this;
    }
    ```

  - [后置++](https://www.imooc.com/video/9588/0)

  ```cpp
  //Coordinate operator++(int) // int 并不是传入的值， 只是一个标记
  //coor1++; // coor1.operator++(0);
  Coordinate operator++(int)
  {
      Coordinate old(*this);
      m_iX++;
      m_iY++;
      return old;
  }
  ```

## 4-4 二元运算符重载

    `- + `

需要临时变量

```cpp
// 成员函数重载
Coordinate& operator+(const Coordinate&);
coor3 = coor1 + coor2; // coor3 = coor1.operator+(coor2)

# 友元函数重载
friend Coordiate& operator(const Coordinate&, const Coordinate&)

coor3= coor1 + coor2; // coor3 = operator+(coor1, coor2)
```

- `<<`

输出运算符重载, `必须使用友元函数重载, 因为使用了ostream`

```cpp
friend ostream& operator<<(ostream& out, const Coordinate&)

friend ostream& operator<<(ostream& out, const Coordinate& coor){
    out<< coor.m_iX << m_iY <<;
    return out;
}

eg：
cout << coor; //operator<<(cout, coor);
```

索引运算符, `必须使用成员函数重载， 因为必须有this 指针`

```cpp
int operator[](int index){
    if(0 == index）{
        return m_iX;
    }
    if(1 == index){
        return m_iY;
    }
}

eg：
Coordinate coor(1,2);
cout << coor[0]; //coor.operator[](0)
cout << coor[1]; //coor.operator[](1)
```

## 5. 模板函数和模板类

- template
- typename
- class

```cpp
Template <class T>
T max(T a, T b){
    return (a>b?)a:b;
}

eg：
int ival = max(100,99);
char cval = max<char>('a', 'b');
```

类型作为模板参数

```cpp
template<typename T>
void swap(T& a , T& b){
    T temp = a; a = b; b = a;
}

eg：
int x =20, y= 30;
swap<int>(x,y)
```

变量作为模板参数

```cpp
temp <int size>
void display(){
    cout << size << endl;
}

eg：
display<10>();
```

多个参数

```cpp
template <typename T, typename C>
void display(T a, C b){
    cout << a << b << endl;

}

eg：
int a = 1024; string str = "hello world!";
display<int,string>(a,str);
```

typename class 可以混用

```cpp
display<int, 5>(15);
```

## 函数的模板和重载

模板函数重载
类模板

```cpp
template <class T>
class MyArray{
public:
    void display()'
}

template <class T>
void MyArray<T>::display(){

}

```

模板代码不能分离编译

## 6 标准模板库

## vector 向量

对数组的封装， 功能强大的数组， 自动变长，读取能在常数时间完成。
初始化方法
常用的函数

- empty
- begin end 迭代器
- clear
- front
- back
- size
- push_back
- pop_back

迭代器

```cpp
vector<string>::iterator citer = vec.begin();
for(;citer != vec.end();citer++)
{cout << *citer << endl;}
```

## 链表

数据插入的速度快

## 映射

key value

```cpp
map<int, string> m ;
pair<int, string> p1(10,"shanghai");
pair<int, string> p2(20,"beijing");
m,insert(p1);
m.insert(p2);
cout << m[10] <<endl;
cout << m[20] <<endl;
```
