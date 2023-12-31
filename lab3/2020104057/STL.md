| 类型           |                         特点                          |                     应用场景                      |
| -------------- | :---------------------------------------------------: | :-----------------------------------------------: |
| vector         |     动态数组，支持随机访问和快速尾部插入删除操作      |     适用需要频繁访问元素和动态调整大小的场景      |
| list           |    双向链表  支持快速插入/删除操作  不支持随机访问    | 适用于需要频繁插入/删除元素而不关心随机访问的场景 |
| `deque`        | 双向开口的动态数组  支持随机访问快速头尾插入/删除操作 |    适用于需要在头尾进行频繁插入删除操作的场景     |
| stack          |     先进后出的容器，只能在栈顶进行插入和删除操作      |           适用于需要先进后出操作的场景            |
| queue          |      先进后出的容器，只能在队尾插入，在队头删除       |           适用于需要先进后出的操作场景            |
| priority-queue |      给予堆的容器，元素按照一定的优先级进行排序       |        适用于需要按照优先级处理元素的场景         |
| set            |  有序不重复元素的容器，支持快速查找、插入和删除操作   |            适用于快速查找和去重的场景             |

表中，对于容器有顺序容器和关联容器之分：

顺序容器：

1. `vector` & `array`：结合单词的直译：vector是向量，array是数列的意思。二者的区别是，`vector`可以动态改变，`array`不可改变容器的大小，空间不足时需创造更大的空间，并把之前的数据拷贝到新空间中。`vector`使用更加灵活的动态空间。
2. `deque`：结合dequeue（出列、离队），这的容器，是一个双端开口的容器，两端都可以插入删除元素，但访问速度比vector慢。
3. `queue`：结合queue（排队、队列），该种容器是，先进先出的单端开口存储器，只能从尾部插入，头部删除
4. `list`：结合list（列表、清单、(按某次序)把…列表）list是环状双向链表，相对于vector的连续空间，list的空间是分散的，可以动态分配存储，对空间的利用很精确。
5. `stack`：stack（堆栈），是先进后出的数据结构，只有一个出口，只能在栈顶插入或删除元素。

关联容器：

1. `map/set`：map中所以的元素都是pair类型，它拥有key（键值）和value（实值）两个属性，是一种一对一的关系。
   map中的元素会根据键值来进行自动排序。map的底层实现是红黑树，不能有重复元素。
   set的底层实现也是使用红黑树，所有元素在插入时被自动排序，且set中不允许有重复值。
2. `multimap/multiset`：`multimap与multiset`底层使用的都是红黑树，只不过在插入元素的时候，调用的是红黑树的nsert_equal()函数，所以可以有重复元素。
[STL.md](https://github.com/chengjizhao/JNU-Cplusplus-labs/files/13623266/STL.md)
