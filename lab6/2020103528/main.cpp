#include <iostream>
#include <cstdint>
#include <cstdlib>

#include "SampleClass.h"

using namespace std;


int main() {
    
    SampleClass sc;

    // 无法直接获得私有方法的指针
    // auto p = SampleClass::private_method;
    // auto p = SampleClass::static_private_method;
    // 都是错误的
    

    // 间接获取静态方法的指针，再调用静态私有方法
    auto p = sc.get_private_method_ptr();
    p();

    cout << endl;

    // 无法用任何方法获取非静态私有方法的指针
    // 通过公有方法调用非静态私有方法
    sc.call_private_method();

    // 实际上，如果知道类中成员函数和成员变量的相对地址，
    // 理论上是可以通过指针偏移的方式访问任何一个私有成员。
    // 然而此种方式违背类的封装原则，是不应使用的。
	
	system("pause");
    return 0;
}