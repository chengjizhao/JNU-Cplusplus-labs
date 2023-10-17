#include<iostream>
#include"person.h"
using namespace std;

int main()
{
    string p2_name="小红";
    string p2_id = "441245744452211455";
    char p2_gender='w';
    float p2_height = 168.5;
    float p2_weight = 55.36;
    int p2_birth_date = 20050228;
    
    string p3_name="小明";
    string p3_id="441258654412358744";
    char p3_gender='m';
    float p3_height = 187.8;
    float p3_weight = 85.4;
    int p3_birth_date = 20031203;

    person p1;
    person p2(p2_id);
    person p3(p3_name,p3_id,p3_gender,p3_height,p3_weight,p3_birth_date);

    cout<<"打印对象的存储空间："<<endl;
    cout<<"sizeof(p1)  "<<sizeof(p1)<<endl; //80
    cout<<"sizeof(p2)  "<<sizeof(p2)<<endl; //80
    cout<<"sizeof(p3)  "<<sizeof(p3)<<endl; //80
/*
    解释:
    1. 对象所占内存大小就成员变量所占的大小之和，成员函数不占内存空间；
    2. string类型占32字节，int类型占4字节，float类型占4字节，char类型占4字节；
        2.1 string类型实际上所占的空间是从堆中动态分配的，所以实际的字符串长度和所占空间没有关系，在相同库下sizeof(string)是固定的。
            不同库的string类型可能sizeof会不同。string的实现大概长这样
            class {
                char *_Ptr;    //指向字符串的指针
                int _Len;      //字符串的长度
                ........ 
            }; 
        2.2 和结构体类似，创建的class对象也存在内存对齐现象，所以本来占1个字节的char，由于内存对齐，就占了4个字节。
    3.所以总字节数为：32+32+4+4+4+4 = 80 (byte)
*/
    show_Info(p1);
    cout<<endl;
    show_Info(p2);
    cout<<endl;
    show_Info(p3);
    cout<<endl;

    //调用设置函数设置p2的信息重新打印
    p2.set_name(p2_name);
    p2.set_gender(p2_gender);
    p2.set_height(p2_height);
    p2.set_weight(p2_weight);
    p2.set_birth_date(2005,2,28);
    show_Info(p2);


    return 0;
}