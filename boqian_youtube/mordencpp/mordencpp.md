- initializer list:

```cpp
//c++ 03 initializer list
int arr[4] = {3,4,2,5};
vector<int> v;
v.push_back(3);
v.push_back(4);
v.push_back(5);
v.push_back(2);
//c++ 11
vector<int> v = {3,4,52,2}; //Calling initializer_list constructor
// all the relevent STL containers have been updated to accept initializer_list.
```

- uniformed initialization
  - initializer_list
  - constructor
  - 符合类型初始化

## auto type

- c++03 iterator

```cpp
std::vector<int> vec = {2,3,4,5};
for (std::vec<int>iterator it = vec.begin()l it != vec.end();++it){
    m_vec.push_back(*it);
}

```

- c++11 use auto type

```cpp
for (auto it = vec.begin();it!= vec.end();++it)
{
    m_vec.push_back();
}
```

## foreach

```cpp
//c++03
for(vector<int>::iterator itr = v.begin();itr != vec.end();++itr){
    cout << *itr;
}
//c++11
for(auto i:v) { //works on any class that has begin() and end(), readonly access in v
    cout << i;
}
for(auto &i:v){
    i++; //changes the value in v
}
```

## 5. nullptr

replace NULL in c++03

```cpp
void foo(int i) {std::cout<< "foo_int" << std::endl;}
void foo(char * pc){std::cout << "foo_char*"<< std::endl;}
int main() {
    //foo(NULL); // Ambiguity -- > error: call to 'foo' is ambiguous
    foo(0); // Ambiguity -- > error: call to 'foo' is ambiguous
    //c++11
    foo(nullptr); //call foo(char*)
}
```

## 6. enume class

```cpp

int main() {

//    enum apple {green_a, red_a,};
//    enum orange { big_o, small_o};
//
//    apple a =green_a;
//    orange o = big_o;
//
//    if (a == o) { //always true
//        std::cout <<"green apple and big orange are the same" << std::endl;
//    }
//    else {
//        std::cout<< "green apple and big orange are not the same " << std::endl;
//    }
//


//c++11
    enum class apple {green_a, red_a,};
    enum class orange { big_o, small_o};

    apple a =apple::green_a;
    orange o = orange::big_o;

    if (a == o) { // compile failed, because appe == orange is not defined
        std::cout <<"green apple and big orange are the same" << std::endl;
    }
    else {
        std::cout<< "green apple and big orange are not the same " << std::endl;
    }

    return 0;
}

```

## 7.static_assert

```cpp
int main() {

    //runtime assert
    int * mypointer = nullptr;
    assert(mypointer != nullptr);

    //compile time assert (c++11)
    static_assert(sizof(int) ==4);
    return 0;
}
```

## 8. Delegating constructor

```cpp
class dog { // works only in java?
    public:
    dog() {};
    dog(int) {dog(); doOtherThings(a)}
};
// c++03
class dog{
    init(){};
    public:
    dog(){init()};
    dog(int a ) {init(); doOtherThings();}
}
// c++11
class dog{
    public:
    doOtherThings(){}
    dog(){};
    dog(int a):dog(){doOtherThings();}
}
```

## 9. override(for virtual function)

```cpp
//c++ 03
class dog{
    virtual void A(int);
    virtual void B() const;
}
class yellowdog:public dog{
    virtual void A(float); // created a new function
    virtual void B(); //created a new function
}
//c++ 11
#include <iostream>

class dog{
    virtual void A();
    virtual void B() const;
    void C();
};

class yellowdog:public dog{
    void A(int) override;
    void B() override;
    void C() override ;
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

## 10. final (for virtual function and for class)

```cpp
class dog final { // no class can be derived from dog
    ...
}
class dog {
    virtual void bark() final; // no class can override bark();
}
```

## 11. compiler generated default constructor

```cpp
//c++03
class dog {
    dog(int age){}
};

dog d1; //Error: compiler will not generate the default constructor.
//c++11
class dog{
    dog(in age);
    dog() = default; // Force compiler to generate the default constructor.
};

```

## 12. delete

```cpp
//c++03
class dog{
    dog(int age){}
};
dog a(2); //ok
dog b(3.0) // ok, 3.0 is converted from double to int
a = b; // ok, compiler generated assignment operator.

//c++11
class dog{
    dog(int age) {}
    dog(double) = delete;
    dog & operator=(const dog&) = delete;
}

```

## 13. constexpr

```cpp
// c++03
int arr[6]; // ok
int A() {return 3;} // ok
int arr[A() +3] // array size is very big

//c++11
#include <iostream>
constexpr int A() {return 3;} /// force the computation to happen at compile time
constexpr int cubed(int x) {return x*x*x;}
int main() {

    int arr[A() +3];// create an array of size 6

// write faster program with constexpr

    int y = cubed(1789); // computed at compile time
    return 0;
}
```

## 14. New string literals

```cpp
//c++03

char * a = "string";
//c++11
char* a = u8"string"; // utf-8
char16_t* b = u"string"; // utf-16
char32_t* b = U"string"; // utf-32
char* d = R"string \\"; //raw string

```

## 15. lambda function

```cpp
cout << [](int x, int y){return x+y}(3,4) << endl;
auto f = [](int x, int y) {return x+y};
cout << f(3,4) << endl;

#include <iostream>
#include <vector>

template<typename func>
void filter(func f, std::vector<int> arr) {
    for(auto i:arr) {
        if(f(i))
            std::cout << i << " ";
    }
    std::cout<< std::endl;
}
int main() {

        std::vector<int> v = {1,2,3,4,5,6};
        filter([](int x) {return (x>3);}, v);
        filter([](int x) {return (x > 2 && x <5);},v);
        int y = 4;
        filter([&](int x){return (x > y);}, v);
// Note: [&] tells compiler that we want variable capture.
    return 0;
}
```
