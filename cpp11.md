# C++ 11

## Type inference

 auto

## range based for loop

```cp
for (auto& x : my_array){
    x *= 2；
}
```

## Nonmember begin and end

## Move / &&

``` cpp
vector<int> v;
int a[100]

sort(begin(v), end(v))
sort(begin(a), end(a))
```

## Lambda functions and expressions

``` cpp0
[](int x, int y) -> int { return x + y;}
```

## Uniform Initialization and Initializer Lists

``` cpp
rectangle w {origin(), extends()};
complex<double> c {2.71828, 3.1415926};
int a[] {1, 2, 3, 4};
vector<int>v {1，2，3，4}；
```

## [nullptr,  the pointer literal](http://en.cppreference.com/w/cpp/language/nullptr)

C++98

    add new feature RTTI(dynamic_cast/typeid)

[mutex](http://www.cplusplus.com/reference/mutex/lock/)
[thread](http://www.cplusplus.com/reference/thread/thread/)
[atomic](http://www.cplusplus.com/reference/atomic/atomic)

 null-terminated character strings

 stack-based scope instead of heap or static global scope
 smart pointers instead of raw pointers
 std::string and std:wstring instead of char[]
 standard containers like vector list map instead of raw arrays or custom containers
 standard library algorithms instead of manually coded ones
 exceptions
 lock-free inter-thread communication using C++ std::atomic<> instead of other inter-thread communicatins mechanisms.
 inline lambda functions instead of small functions implemented separately
 range based loops

 In modern C++, you don't have to use new/delete or explicit exception handling because you can use smart pointers instead

 [welcome-back-to-cpp-modern-cpp](https://docs.microsoft.com/en-us/cpp/cpp/welcome-back-to-cpp-modern-cpp)

Objects Own Resources (RAII)

Make sure that objects own resources. This principle is also known as “resource acquisition is initialization” or “RAII.”

## [alignof operator](http://en.cppreference.com/w/cpp/language/alignof)

[elements-of-modern-c-style](https://herbsutter.com/elements-of-modern-c-style/)

## chrono

time/calander

## thread

mutual exclusion
class mutex
lock_guard  unique_lock shared_lock

condition variables
future

[cpp11NotesSample](https://www.artima.com/samples/cpp11NotesSample.pdf)