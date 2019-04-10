/*
function:
	travis implementation of mutex 

build :
	g++ -std=c++11  mutex.cpp  -pthread

result:
	root@zz:~/src/shell_learning/playground# ./a.out
	In main: creating thread 0
	In main: creating thread 1
	Hello World! It's me, thread #0!
	In child, get the lock #0
	In main: creating thread 2
	In main: creating thread 3
	In main: creating thread 4
	Hello World! It's me, thread #1!
	Hello World! It's me, thread #2!
	Hello World! It's me, thread #3!
	Hello World! It's me, thread #4!
	In child, get the lock #2
	In child, get the lock #4
	In child, get the lock #3
	In child, get the lock #1

reference:
	https://computing.llnl.gov/tutorials/pthreads/
	http://en.cppreference.com/w/cpp/atomic/atomic
*/

#include <sys/types.h>
#include <atomic>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 5
using namespace std;

typedef struct mutex
{
    std::atomic<pid_t> owner;
} mutex_t;

mutex_t *m;

mutex_t *mutexInit()
{
    return (mutex_t *)malloc(sizeof(struct mutex));
}
int lock(mutex_t *l)
{
    while (1)
    {
        if (l->owner == 0)
        {
            l->owner = syscall(SYS_gettid);
            return 0;
        }
        sleep(1); // sleep to save power, otherwise CPU is highss
    }
}
int unlock(mutex_t *l)
{
    if (l->owner == syscall(SYS_gettid))
    {
        l->owner = 0;
        return 0;
    }
    return -1;
}

int lockDestroy(mutex_t *l)
{
    if (l->owner == 0)
    {
        free(l);
        return 0;
    }
    return -1;
}

void *PrintHello(void *threadid)
{
    long tid;
    tid = (long)threadid;
    printf("Hello World! It's me, thread #%ld!\n", tid);
    lock(m);
    printf("In child, get the lock #%ld\n", tid);
    sleep(3);

    unlock(m);
    pthread_exit(NULL);
}

int main()
{

    m = mutexInit();

    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for (t = 0; t < NUM_THREADS; t++)
    {
        printf("In main: creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    sleep(20); // wait for all thread to exit
    lockDestroy(m);
    /* Last thing that main() should do */
    pthread_exit(NULL);
}
