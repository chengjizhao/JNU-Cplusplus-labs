#include<iostream>
using namespace std;

class MyClass {  
public:  
    virtual void func1() { std::cout << "func1**" << std::endl; }  
    virtual void func2() { std::cout << "func2*" << std::endl; }  
};  
  
int main() {  
    MyClass obj;  
    // 获取vptr（假设它是对象的第一个成员）  
    void** vptr = (void**)&obj;  
    // 访问vtable  
    void* vtable = *vptr;  
    // 假设vtable的第一个元素是指向func1的函数指针  
    void (*funcPtr)() = *(void(**)())vtable;  
    // 调用func1  
    funcPtr();  
}
//这段代码尝试通过vptr访问vtable，并调用其中的第一个函数。