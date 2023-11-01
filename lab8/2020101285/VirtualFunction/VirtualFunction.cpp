#include <iostream>
using namespace std;

class BaseClass {
public:
    virtual void func1() {
        cout << "BaseClass::func1() called" << endl;
    }
    virtual void func2() {
        cout << "BaseClass::func2() called" << endl;
    }
};

class DerivedClass : public BaseClass {
public:
    virtual void func1() {
        cout << "DerivedClass::func1() called" << endl;
    }
};

int textRef() { return 0 ;}

int main() {
    //内存区域参考,以便比较
    int stackRef = 1 ;          //内存栈区的地址参考
    static int staticRef = 1;   //内存全局静态区的地址参考
    int* heapRef = new int ;    //内存堆区的地址参考
    int (*pText)() = textRef;   //内存代码段的地址参考
    cout << "text segment : " << reinterpret_cast<void*>(pText) << endl;
    cout << "stack segment: " << &stackRef <<endl;
    cout << "heap segment: " << heapRef <<endl;
    cout << "static segment: " << &staticRef <<endl;
    cout <<"______________________________________________________" << endl ;


    BaseClass* pBaseObj1 = new BaseClass;
    DerivedClass* pDerivedObj1 = new DerivedClass;
    DerivedClass* pDerivedObj2 = new DerivedClass;

    // 转换为指向虚函数表的指针
    void** vtable1 = reinterpret_cast<void**>(pBaseObj1);
    void** vtable2 = reinterpret_cast<void**>(pDerivedObj1);
    void** vtable3 = reinterpret_cast<void**>(pDerivedObj2);

    //转换为虚函数表内首元素（指向虚函数的指针）的指针
    void** vtable1_func = *reinterpret_cast<void***>(pBaseObj1);
    void** vtable2_func = *reinterpret_cast<void***>(pDerivedObj1);
    void** vtable3_func = *reinterpret_cast<void***>(pDerivedObj2);

    //获取了虚函数的地址，可通过函数指针p直接调用虚函数。
    void (*p)();
    p = (reinterpret_cast<void(*)()>(vtable1_func[0]));
    p();
    p = (reinterpret_cast<void(*)()>(vtable2_func[1]));
    p();

    /******    下面验证虚函数实现的内存结构    ***********/
    //打印对象地址
    cout<<"BaseObj1 address: "<<pBaseObj1<<"\tDerivedObj1 address: "<<pDerivedObj1<<"\tDerivedObj2 address: "<<pDerivedObj2<<endl;
    //打印vptr的值，即虚函数表的地址
    cout<<"vtable1 address: "<<*vtable1<<"\tvtable2 address: "<<*vtable2<<"\tvtable3 address: "<<*vtable3<<endl;
    //打印虚函数地址
    cout<<"BaseClass::func1() address: "<<vtable1_func[0]<<"\tBaseClass::func2() address: "<<vtable1_func[1]<<endl;
    cout<<"DerivedClass::func1() address: "<<vtable2_func[0]<<"\tDerivedClass::func2() address: "<<vtable2_func[1]<<endl;

    return 0;
}

