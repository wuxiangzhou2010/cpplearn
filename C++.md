# cpp

## [string](./string.md)

## [STL](./stl/stl.md)

## [Thread(c++11)](./thread/thread.md)

### std::future , std::promise and Returning values from Thread

- std::future is a class template and its object stores the future value.
- std::promise is also a class template and its object promises to set the value in future. Each std::promise object has an associated std::future object that will give the value once set by the std::promise object.

## std::async Tutorial & Example

- std::launch::async

  It guarantees the asynchronous behaviour i.e. passed function will be executed in seperate thread.

- std::launch::deferred

  Non asynchronous behaviour i.e. Function will be called when other thread will call get() on future to access the shared state.

- std::launch::async | std::launch::deferred

  Its the default behaviour. With this launch policy it can run asynchronously or not depending on the load on system. But we have no control over it.

[cpp11NotesSample](https://www.artima.com/samples/cpp11NotesSample.pdf)

## Input/Output(iostream, fstream)

cout/cin

## FileSystem(path,)(c++2017)

## Random library

## Algorithm (Sorting, Binary search, Minimum/maximum )

## C++ 11 feature

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

```cpp
vector<int> v;
int a[100]

sort(begin(v), end(v))
sort(begin(a), end(a))
```

## [Lambda functions and expressions](https://solarianprogrammer.com/2011/11/01/cpp-11-lambda-tutorial/)

```cpp
[](int x, int y) -> int { return x + y;}
```

## [C++14 auto type lambda functions](https://solarianprogrammer.com/2014/08/28/cpp-14-lambda-tutorial/)

## Uniform Initialization and Initializer Lists

```cpp
rectangle w {origin(), extends()};
complex<double> c {2.71828, 3.1415926};
int a[] {1, 2, 3, 4};
vector<int>v {1，2，3，4}；
```

## [nullptr, the pointer literal](http://en.cppreference.com/w/cpp/language/nullptr)

C++98

    add new feature RTTI(dynamic_cast/typeid)

[mutex](http://www.cplusplus.com/reference/mutex/lock/)
[thread](http://www.cplusplus.com/reference/thread/thread/)
[atomic](http://www.cplusplus.com/reference/atomic/atomic)

- stack-based scope instead of heap or static global scope
- smart pointers instead of raw pointers
- std::string and std:wstring instead of char[]
- standard containers like `vector` `list` `map` instead of raw arrays or custom containers
- standard library algorithms instead of manually coded ones
- exceptions
- lock-free inter-thread communication using C++ std::atomic<> instead of other inter-thread communicatins mechanisms.
- inline lambda functions instead of small functions implemented separately
- range based loops

- welcome-back-to-cpp-modern-cpp
  In modern C++, you don't have to use new/delete or explicit exception handling because you can use `smart pointers` instead

[welcome-back-to-cpp-modern-cpp](https://docs.microsoft.com/en-us/cpp/cpp/welcome-back-to-cpp-modern-cpp)

- Objects Own Resources (RAII)

  Make sure that objects own resources. This principle is also known as “resource acquisition is initialization” or “RAII.”

## [alignof operator](http://en.cppreference.com/w/cpp/language/alignof)

[elements-of-modern-c-style](https://herbsutter.com/elements-of-modern-c-style/)

## chrono

time/calander
