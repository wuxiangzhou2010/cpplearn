# libevent

[libevent源码分析](http://www.cnblogs.com/hustcat/archive/2010/08/31/1814022.html)

libevent 的源代码虽然都在一层文件夹下面，但是其代码分类还是相当清晰的，主要可分为头文件、内部使用的头文件、辅助功能函数、日志、libevent 框架、对系统 I/O 多路复用机制的封装、信号管理、定时事件管理、缓冲区管理、基本数据结构和基于 libevent的两个实用库等几个部分，有些部分可能就是一个源文件。

（1）头文件
    主要就是 event.h：事件宏定义、接口函数声明，主要结构体 event 的声明；
（2）内部头文件
    xxx-internal.h：内部数据结构和函数，对外不可见，以达到信息隐藏的目的；
（3）libevent框架
    event.c：event 整体框架的代码实现；
（4）对系统 I/O多路复用机制的封装
    epoll.c：对 epoll 的封装；
    select.c：对 select 的封装；
    devpoll.c：对 dev/poll 的封装;
    kqueue.c：对kqueue 的封装；
（5）定时事件管理
        min-heap.h：其实就是一个以时间作为 key的小根堆结构；
（6）信号管理
    signal.c：对信号事件的处理；
（7）辅助功能函数
    evutil.h  和 evutil.c：一些辅助功能函数，包括创建 socket pair和一些时间操作函数：加、减和比较等。
（8）日志
    log.h和 log.c：log 日志函数
（9）缓冲区管理
evbuffer.c 和buffer.c：libevent 对缓冲区的封装；
（10）基本数据结构
compat\sys 下的两个源文件： queue.h是 libevent 基本数据结构的实现，包括链表，双向链表，队列等；_libevent_time.h：一些用于时间操作的结构体定义、函数和宏定义；
（11）实用网络库
     http 和evdns：是基于 libevent 实现的http 服务器和异步 dns 查询库；