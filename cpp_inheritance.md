# C++远征之继承篇

基类和派生类：is a 关系

## 2. 为什么继承

## 3. 继承的方式

- pubic 继承

  在子类中的访问与父类中无异
  public --> public
  protected --> protected
  private --> 不可访问

- 保护继承

  public --> protected
  protected --> protected
  private --> 不可访问

- 私有继承
  public --> private
  protected --> private
  private --> 不可访问

## 4. 继承中的特殊关系

- 4-1 隐藏

  子类中的同名函数隐藏父类中同名的函数

- 4-2

## 构造函数执行的顺序

    1. 调用基类构造函数，调用顺序按照它们被继承时声明的顺序（从左到右）；
    2. 调用内嵌成员对象的构造函数，调用顺序按照它们在类中声明的顺序；
    3. 派生类的构造函数体中的内容。

## 5. 多继承 与 多重继承

## 6. [虚继承](https://zh.wikipedia.org/wiki/%E8%99%9A%E7%BB%A7%E6%89%BF)

- 菱形继承, 重定义-->用 ifndefine, define, endif
- 虚继承

```cpp
class Worker:virtual public Person{};
class Farmer:virtual public Person{};
class MigrantWorker:public Worker, public Farmer{};
```

- 抽象类 - 接口类

  - 如果类中至少有一个函数被声明为纯虚函数， 则这个类就是抽象类。
  - 抽象类不能被用于实例化对象， 只能作为接口使用。
