#include<iostream>
#include"person.h"
using namespace std;
int main()
{
    person person1;
    person person2("conan","12345","960504","man",130,30);
    cout<<"p1的大小:"<<sizeof(person1)<<endl;
    cout<<"p2的大小:"<<sizeof(person2)<<endl;
    return 0;
}
//类的大小的计算遵循结构体的对齐原则，与普通数据成员有关，与成员函数和静态成员无关