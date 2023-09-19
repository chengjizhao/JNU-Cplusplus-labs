#include<list>
#include<vector>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
    clock_t start, v_time,l_time;//定义时间量 本质是long型  
    int size=80;//定义容器容量
    vector<int>v(80);
    list<int>l(80);
    srand(time(0));
    start=clock();//clock（）函数获取当前时间
    auto iter_v=v.begin();//auto万金油类型编译器会自动寻找iter匹配的类型，此为定义迭代器的简约写法\
    可以换成为 vector<int>::iterator iter_v;
    for(int i=0;i<10000;i++)
    {   
        advance(iter_v,rand()%(size-1));//迭代器向前指向，rand（）是随机正数，取余操作是由于余数小于除数\
        故是取容量范围内的随机数
        v.insert(iter_v,i);
        size++;//每插入一个数，容量加一
        iter_v=v.begin();//因为advance取的是相对位置，故迭代器要指向头部
    }
    v_time=clock()-start; 
    cout<<"vector随机插入延迟为："<<v_time<<"ms"<<endl;
    start=clock();
    auto iter_l=l.begin();
    for(int i=0;i<10000;i++)
    {   
        advance(iter_l,rand()%(size-1));
        l.insert(iter_l,i);
        size++;
        iter_l=l.begin();
    }
    l_time=clock()-start;
    cout<<"list随机插入延迟为："<<l_time<<"ms"<<endl;
}