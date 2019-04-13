- initializer list:
``` cpp
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
``` cpp

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