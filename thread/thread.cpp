//#include <iostream>
//#include <thread>
//#include <vector>
//#include <mutex>
//
//void threadWork(){
//    std::cout<< "testtest" <<std::endl;
//}
//static  const int  nr_thread = 100;
//std::mutex mu;
//
//int main() {
////    std::thread t[nr_thread];
//    std::vector<std::thread> t;
//    for (int i =0; i< nr_thread;i++)
//    {
//        mu.lock();
//        t.push_back(std::thread(threadWork));
//        fflush(stdout);
//        mu.unlock();
//    }
//    for(auto &th: t)
//    {
//        th.join();
//    }
//    return 0;
//}

//#include <iostream>
//
//
//int main()
//{
//    auto i = 11;
//    std::cout << alignof(unsigned long long) << std::endl;
//}

//  a simple c++11 thread test
// compile: g++ -lpthread
// reference:
// https://solarianprogrammer.com/2011/12/16/cpp-11-thread-tutorial/

// launch a thread using c++11 thread
// #include <iostream>
// #include <thread>
//
// void call_from_thread()
// {
//     std::cout << "hello, world" << std::endl;
// }
//
// int main()
// {
//     std::thread t1(call_from_thread);
//     t1.join();
//     return 0;
// }

// launch a thread using POSIX thread
// #include <iostream>
// #include <pthread.h>
//
// void *call_from_thread(void *)
// {
//     std::cout << "launched by thread" << std::endl;
//     return NULL;
// }
//
// int main()
// {
//     pthread_t t;
//     pthread_create(&t, NULL, call_from_thread, NULL);
//     pthread_join(t, NULL);
//     return 0;
// }

// using c++11 thread to launch 10 thread
// 1. 使用数组存储线程变量
// 2. 使用锁来保证临界资源的访问
// #include <iostream>
// #include <thread>
//
//#include <mutex>
//
//std::mutex mu;
// void call_from_trhead()
// {
//     mu.lock();
//     std::cout << "launched by thread" << std::endl;
//     mu.unlock();
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

// 1. 使用线程同步 mutex 来保证对临界资源 stdout 的访问
// 2. vector 的使用
// 3. 线程的创建， 传参， 线程的等待
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mu;
void func(int tid)
{
    mu.lock();
    std::cout << "Launched by thread" << tid << std::endl;
    mu.unlock();
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
