#include<string>//字符串
#include<vector>//动态数组
/*
可以简单理解为是一个可以存放任意类型的动态数组
vector适合需要高效率存储，需要随机访问，并且不管行插入和删除效率的场景。
*/
#include<list>//双向链表(list<type>Name)
/*
list中的元素是分散在内存空间中的,其各个元素的前后顺序是靠指针互相联系的.
list可以在序列中已知的任何位置插入或者删除元素,其移动元素的效率比其他容器都要高.
但是list不能像vector一样直接按位置访问元素.
list可以在头部插入删除元素.
在list中可以用sort()排序,用unique()删除相邻重复元素只保留一个
list适合有大量的插入和删除操作，并且不关心随机访问的场景
*/
#include<deque>//双端队列容器(deque<type>Name)
/*
deque可以在头部插入删除元素.
deque的本质是数组
*/
#include<queue>//队列容器(包含优先队列)(与栈定义类似)
//(注意定义的底层容器类型不能vector,vector和栈类似只能在一端操作)
/*
先进先出.
队的基本操作为判断队空,求队头求队尾求队大小,入队出队
*/
#include<stack>//堆栈容器(stack<type,底层容器类型默认是deque>Name)
/*
先进后出.
栈的基本操作有判断栈空,求栈顶,求栈大小,入栈出栈.
eg.遍历栈需要当栈顶不为空时出栈
*/
#include<map>//
using namespace std;//所有容器都需要用到该命名空间
void Vector()
{
   
}
int main()
{
    return 0;
}