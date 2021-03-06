简单对象模型（a simple object model）和表格驱动对象模型（a table-driven object model）

- C versus C++
  http://unthought.net/c++/c_vs_c++.html

C++ tutorial:
https://www.tutorialspoint.com/cplusplus

- Data Hiding(Data Encapsulation()

  - access specifiers(public, protected, private)

    protected: they can be accessed in child classes which are called derived classes

- Inheritance

  class derived-class: access-specifier base-class (access-specifier: private by default)

- Polymorphism

  - (means having many forms. Typically, polymorphism occurs when there is a hierarchy of classes and they are related by inheritance.)
  - (a call to a member function will cause a different function to be executed depending on the type of object that invokes the function)
  - (Defining in a base class a virtual function, with another version in a derived class, signals to the compiler that we don't want static linkage for this function.)
  - early binding/late binding
  - dynamic linkage/static linkage
  - virtual/pure virtual function ( virtual int area() = 0;)

- Overloading

  allows you to specify more than one definition for a function name or an operator in the same scope

  - function overloading
  - operator overloading

    function overloading -> different iin types and/or the number of arguments
    overload resolution

- This pointer:

  this pointer is the pointer to the object itself

- Pointer to Class:

  A pointer to a C++ class is done exactly the same way as a pointer to a structure and to access members of a pointer to a class you use the member access operator -> operator, just as you do with pointers to structures. Also as with all pointers, you must initialize the pointer before using it.

- constructor
- destructor
- static member:

  - static function member:

  1. A static member function `can only access static data member`, other `static member functions` and any other `functions from outside the class`.
  2. static member functions `have a class scope` and they `do not have access to the this pointer` of the class.

- Data Abstraction
- file stream
- error/exception handling

  Exceptions provide a way to transfer control from one part of a program to another.

  - try/catch/throw/

http://www.idt.mdh.se/kurser/cd5130/msg/HT2000/download/CppOM.pdf
http://lifegoo.pluskid.org/upload/doc/object_models/C++%20Object%20Model.pdf

## Advanced topic

- VPTR 的原理

  C++ 是用 C 实现的， C++有的功能都能用 C 来解释
  C++ containers
  C++ STL
  C++ boost libraries

- Dynamic memory:

  stack/heap

- Multiprocess/MultiThreading

  POSIX pthread/c++ 11 thread library

reference:

- [inside.the.c++.object.model](http://www.faq3.de/OrganizeMe/pg/pdf/inside.the.c++.object.model.pdf)
