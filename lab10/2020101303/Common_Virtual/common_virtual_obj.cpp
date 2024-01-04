#include <iostream>
using namespace std;

//一般类对象+带虚函数的类对象
class SampleClass 
{
    public:
       int a;
       double b; 
       virtual void vBase() {cout << "Virtual Base !" << endl;}
       virtual void Public() {cout << "Public: Base" << endl;}
       void (*fptr)() = nullptr;
};

int main()
{
    SampleClass obj;
    
    //所占内存大小
    cout << "Size of SampleClass: " << sizeof(obj) << " bytes" << endl;
    cout << "Size of a: " << sizeof(obj.a) << " bytes" << endl;
    cout << "Size of b: " << sizeof(obj.b) << " bytes" << endl;
    cout << "Size of ptr: " << sizeof(obj.fptr) << " bytes" << endl;
    cout << endl;

    //地址及调用
    int *a_ptr = &obj.a;
    double *b_ptr = &obj.b;
    *a_ptr = 42;  
    cout << "a =" << *a_ptr << endl;
    cout << "Address of a: " << reinterpret_cast<void*>(a_ptr) << endl;
    cout << "Address of b: " << reinterpret_cast<void*>(b_ptr) << endl; //调用同a

    void (SampleClass::*fptr1)() = &SampleClass::vBase;
    cout << "Address of VirtualFunc vBase: " << reinterpret_cast<void*>(obj.*fptr1) << endl;
    (obj.*fptr1)();
    void (SampleClass::*fptr2)() = &SampleClass::Public;
    cout << "Address of VirtualFunc Public: " << reinterpret_cast<void*>(obj.*fptr2) << endl;
    (obj.*fptr2)();
    return 0;
}