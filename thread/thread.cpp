//  a simple c++11 thread test
// compile: g++ -lpthread
// reference:
// https://solarianprogrammer.com/2011/12/16/cpp-11-thread-tutorial/

// using c++11 thread
// #include <iostream>
// #include <thread>

// void call_from_thread()
// {
//     std::cout << "hello, world" << std::endl;
// }

// int main()
// {
//     std::thread t1(call_from_thread);
//     t1.join();
//     return 0;
// }

// using POSIX thread
// #include <iostream>
// #include <pthread.h>

// void *call_from_thread(void *)
// {
//     std::cout << "launched by thread" << std::endl;
//     return NULL;
// }

// int main()
// {
//     pthread_t t;
//     pthread_create(&t, NULL, call_from_thread, NULL);
//     pthread_join(t, NULL);
//     return 0;
// }

// using c++11 thread to launch 10 thread
// #include <iostream>
// #include <thread>
// void call_from_trhead()
// {
//     std::cout << "launched by thread" << std::endl;
// }
//
// static const int num_threads = 10;
// int main()
// {
//     std::thread t[num_threads];
//     for (int i = 0; i < num_threads; ++i)
//     {
//         t[i] = std::thread(call_from_trhead);
//     }
//     std::cout << "Launched from the main\n";
//     for (int i = 0; i < num_threads; ++i)
//     {
//         t[i].join();
//     }
//     return 0;
// }

#include <iostream>
#include <thread>
#include <vector>

void func(int tid)
{
    std::cout << "Launched by thread" << tid << std::endl;
}

int main()
{
    std::vector<std::thread> th;
    int nr_threads = 10;

    for (int i = 0; i < nr_threads; ++i)
    {
        th.push_back(std::thread(func, i));
    }
    for (auto &t : th)
    {
        t.join();
    }
    return 0;
}