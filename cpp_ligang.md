# C++ 远征之离港篇

## 指针 VS 引用（C++ 语言引用）

- 引用必须初始化

```cpp
int a = 3;
int b& = a;

Coor c1;
Coor &c = c1;
```

- 指针类型的引用

```cpp
int a = 10;
int *p = &a;
int *&q = p;
```

- 引用作为函数参数

```cpp
//使用指针传参
void fun(int *a, int *b) {
    int c = 0;
    c = *a;
    *a = *b;
    *b = c;
}
// int x =10, y = 20;
// fun(&x, &y);


// 使用引用传参
void fun(int &a, int &b) {
    int c =0;
    c= a ;
    a = b;
    b =c;
}
// int x = 10, y = 20;
// fun(x, y)
```

## define VS const

- const 与指针类型
- const 与引用

## C++ 函数默认值 & 函数重载

4-1 C++函数新特性

- 函数参数默认值， 最右边开始写默认值
  - 实参覆盖默认值
- 函数重载 （名称相同，参数可辨）
  - 相同作用域
  - 参数类型不同
  - 参数个数不同
  - 参数类型顺序不同
- 内联函数

## C++ 内存管理

- 内存的申请和释放
  - new 运算符
  - delete 运算符
- 申请块内存

注意事项：

- 申请失败 判断 NULL
- 释放后相应指针置空: 防止重复释放
