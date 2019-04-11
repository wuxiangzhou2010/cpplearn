# Thread(c++11)

## create thread and identify thread

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

## Joining and Detaching Threads

th.join()
th.detach() //also called daemon/background thread
th.joinable() //check if thread joinable before join
thread RAII

## Carefully Pass Arguments to Threads

1. Don’t pass addresses of variables from local stack to thread’s callback function. Because it might be possible that local variable in Thread 1 goes out of scope but Thread 2 is still trying to access it through it’s address.
2. Similarly be careful while passing pointer to memory located on heap to thread. Because it might be possible that some thread deletes that memory before new thread tries to access it.

- using std::ref()
- Assigning pointer to member function of a class as thread function:

## Data Sharing and Race Conditions

- why it happens

  Each thread increments the same “mMoney” member variable in parallel. Although it seems a single line but this “mMoney++” is actually converted into three machine commands,

      Load “mMoney” variable value in Register
      Increment register’s value
      Update variable “mMoney” with register’s value

## Using mutex to fix Race Conditions

mutual exclusion
class mutex
std::mutex m;
m.lock()
m.unlock()
std::lock_guard is a class template, which implements the RAII for mutex.
lock_guard unique_lock shared_lock

## Need of Event Handling

Thread will keep on acquiring the lock and release it just to check the value, therefore it will consume CPU cycles and will also make Thread 1 slow, because it needs to acquire same lock to update the bool flag.

## Condition Variables Explained

    A mutex is required along with condition variable

`<condition_variable>` header

How things actually work with condition variable:

1. Thread 1 calls the wait on condition variable, which internally acquires the mutex and check if required condition is met or not.
2. If not then it releases the lock and waits for Condition Variable to get signaled ( thread gets blocked). Condition Variable’s wait() function provides both these operations in atomic manner.Another Thread i.e. like Thread 2 signals the Condition Variable when condition is met.
3. Once Conditional Variable get signaled the the Thread 1 which was waiting for it resumes. It then acquires the mutex lock again and checks if the condition associated with Condition Variable is actually met or if it is superiors call. If more than one thread was waiting then notify_one will unblock only one thread.
4. If it was a superiors call then it again calls the wait() function.

- Wait()
- notify_one()
- notify_all()

## std::atomic

reference:

- [c-11-multithreading-part-1-three-different-ways-to-create-threads](http://thispointer.com/c-11-multithreading-part-1-three-different-ways-to-create-threads/)
