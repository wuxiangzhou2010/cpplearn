# STL

容器， 算法， 迭代器

## 容器类型

- 顺序结构容器(sequence containers)

  - Vectors 动态数组
  - Lists 链表
  - Double Ended Queues(deque) 双向队列
  - forward list(c++11)
  - array(c++11)

    (array and linked list)

    vector: dynamic array grow in one direction

    vec.size()
    vec[2]
    vec.at(2) // have range check

    常用函数

    - push_back() 在最后添加一个元素
    - pop_back() 移除最后一个元素
    - insert() 插入元素

- 联合容器(associative container) (binary tree)


    常用函数

    - insert()
    - erase()

    sorted no push_back/push_front readonly

- set

  no duplicates

- multiset

  allow duplicatea

  ```cpp
  set<int> myset;
  myset.insert(2)
  ```

  - fast search O(log(n))
  - treaversing is slow(compared to vector and deque)
  - no random access, no []operator

- map/multiple_map

  ```cpp
  map<char, int> mymap;
  mymap.insert(pair<char,int>('a',100));
  mymap.insert(make_pair('z',200));
  ```

- 容器适配器(container adapters)

  - Stacks
  - Queues
  - Prority queues

    常用函数

    - push()
    - pop()

- unordered containers(hash table)

- unordered map/multi_map
- unordered set/multi_set

- fatest search/insert at any place
- associative containers take O(log(n))
  vector,deque takes O(n)
  list take O(1) to insert, O(n) to search

## Reasons to use C++ STL

- code resuse
- Efficiency
- accurate and less bugy
- readable code
- standardization

reference:

- [C++ 标准模板库(STL)汇总](https://blog.csdn.net/DaveBobo/article/details/56497466)

reference:

- [CPP containers](http://en.cppreference.com/w/cpp/container)
