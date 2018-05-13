# cpp

## [characters and strings](https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp9_String.html)

1. cctype

    `isdigit` `isalpha` `isupper` `islower`

1. Basic string

    `std::string` is an instantiation of `std::basic_string<T>`
    `std::basic_string` --> `string` `wstring` `u16string` `u32string`

1. NULL-terminated character strings(char array)

    `<cstring>` header

    char[] is same as char*: C treats an array name as a pointer to the first element of the array
    - size_t strlen (const char * cstr)// not include the null

     `<cstdlib>` header
     - int atoi (char * cstr)
     - double atof (char * cstr)

    `<iostream>` header
    - getline()
    - int cin.get()
    - cin.peek()
    - cin.ignore(unsigned int n = 1, int delim = EOF):

## [CPP containers](http://en.cppreference.com/w/cpp/container)

1. sequence containers
    vector/deque/list
1. associative containers
    set/multiset/map/
1. unordered associative containers.
    unordered_set/unordered_map
1. container adaptors
    stack/queue/prority_queue

iterators/element access/capacity/modifiers

## Thread(c++11)(multiThreading)

### create thread and identify thread

`<thread>` header
attach a callback to thread, can be:
    1.) Function Pointer
    2.) Function Objects
    3.) Lambda functions

```cpp
std::thread t1(CALLBACK)
```

- Member function, gives id of associated thread object,
    std::thread::get_id()

- Gives the identifier for the current thread,
    std::this_thread::get_id()

### Joining and Detaching Threads

th.join()
th.detach() //also called daemon/background thread
th.joinable() //check if thread joinable before join
thread RAII

### Carefully Pass Arguments to Threads

    1. Don’t pass addresses of variables from local stack to thread’s callback function. Because it might be possible that local    variable in Thread 1 goes out of scope but Thread 2 is still trying to access it through it’s address.
    1. Similarly be careful while passing pointer to memory located on heap to thread. Because it might be possible that some thread deletes that memory before new thread tries to access it.

- using std::ref()
- Assigning pointer to member function of a class as thread function:

### Data Sharing and Race Conditions

    - why it happens
    Each thread increments the same “mMoney” member variable in parallel. Although it seems a single line but this “mMoney++” is actually converted into three machine commands,

        Load “mMoney” variable value in Register
        Increment register’s value
        Update variable “mMoney” with register’s value

### Using mutex to fix Race Conditions

mutual exclusion
class mutex
std::mutex m;
m.lock()
m.unlock()
std::lock_guard is a class template, which implements the RAII for mutex.
lock_guard  unique_lock shared_lock

## Need of Event Handling

Thread will keep on acquiring the lock and release it just to check the value, therefore it will consume CPU cycles and will also make Thread 1 slow, because it needs to acquire same lock to update the bool flag.

### Condition Variables Explained

    A mutex is required along with condition variable
`<condition_variable>` header

How things actually work with condition variable:

1. Thread 1 calls the wait on condition variable, which internally acquires the mutex and check if required condition is met or not.
1. If not then it releases the lock and waits for Condition Variable to get signaled ( thread gets blocked). Condition Variable’s wait() function provides both these operations in atomic manner.Another Thread i.e. like Thread 2 signals the Condition Variable when condition is met.
1. Once Conditional Variable get signaled the the Thread 1 which was waiting for it resumes. It then acquires the mutex lock again and checks if the condition associated with Condition Variable is actually met or if it is superiors call. If more than one thread was waiting then notify_one will unblock only one thread.
1. If it was a superiors call then it again calls the wait() function.

Wait()
notify_one()
notify_all()

std::atomic

### std::future , std::promise and Returning values from Thread

std::future is a class template and its object stores the future value.
std::promise is also a class template and its object promises to set the value in future. Each std::promise object has an associated std::future object that will give the value once set by the std::promise object.

## std::async Tutorial & Example

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
