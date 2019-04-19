# STL

容器， 算法， 迭代器

## 容器类型

### 顺序结构容器(sequence containers)

- Vector 动态数组, 底层数据结构为`数组`，支持快速随机访问
- List 底层数据结构为`双向链表`， 支持快速增删
- Double Ended Queues(deque) 双向队列 底层数据结构为一个中央控制器和多个缓冲区，在堆中保存内容, 详细见 STL 源码剖析 P146，支持首尾（中间不能）快速增删，也支持随机访问
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

### 联合容器(associative container) (binary tree)

常用函数

- insert()
- erase()

sorted no push_back/push_front readonly

- set 底层数据结构为红黑树， 有序， 不可重复

- multiset 底层数据结构为红黑树， 有序， 可重复

  ```cpp
  set<int> myset;
  myset.insert(2)
  ```

  - fast search O(log(n))
  - treaversing is slow(compared to vector and deque)
  - no random access, no []operator

- map 底层数据结构为红黑树， 有序， 不重复
- multiple_map 底层数据结构为红黑树， 有序， 不重复

  ```cpp
  map<char, int> mymap;
  mymap.insert(pair<char,int>('a',100));
  mymap.insert(make_pair('z',200));
  ```

### 性能和使用场景

- fatest search/insert at any place
- associative containers take O(log(n))
  vector,deque takes O(n)
  list take O(1) to insert, O(n) to search

### 容器适配器(container adapters)

- Stacks 底层一般用 list 或 deque 实现，封闭头部即可，不用 vector 的原因应该是容量大小有限制，扩容耗时
- Queues 底层一般用 list 或 deque 实现，封闭头部即可，不用 vector 的原因应该是容量大小有限制，扩容耗时（stack 和 queue 其实是适配器,而不叫容器，因为是对容器的再封装）

- Prority queues

  常用函数

  - push()
  - pop()

    priority_queue 根据堆的处理规则来调整元素之间的位置, 根据堆的特性，优先级队列实现了取出最大最小元素时间复杂度为 O(1),对于插入和删除，其最坏情况为 O(lgn)。

- unordered containers(hash table)

  - unordered map 底层数据结构为 hash 表，无序，不重复
  - unordered multi_map 底层数据结构为 hash 表，无序，可重复
  - unordered set 底层数据结构为 hash 表，无序，不重复
  - unordered multi_set 底层数据结构为 hash 表，无序，可重复

## Reasons to use C++ STL

- code resuse
- Efficiency
- accurate and less bugy
- readable code
- standardization

reference:

- [C++ 标准模板库(STL)汇总](https://blog.csdn.net/DaveBobo/article/details/56497466)
- [CPP containers](http://en.cppreference.com/w/cpp/container)
- [C++ STL 几个容器的底层实现 收藏一下](https://blog.csdn.net/single_wolf_wolf/article/details/52854015)
- [总结——STL 常用数据结构及用法](https://blog.csdn.net/xp731574722/article/details/76101089)
- [C++ STL 中的数据结构和算法](https://blog.csdn.net/strint/article/details/45308001)
- [C++ STL 容器底层数据结构总结](https://www.jianshu.com/p/834cc223bb57)
