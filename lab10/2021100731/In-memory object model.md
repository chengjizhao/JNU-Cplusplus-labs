# 内存对象模型
## 1.简单类对象
### 简介
一般来说，一个最简单的类的起始地址即为其第一个变量的地址，且类中不包含成员函数的地址或大小。

### 代码
~~~cpp
//类定义
class Normal_Class
{
public:
    int param;
    void testFunc()
    {
        cout << "testFunc is called!" << endl;
    }
};
~~~
~~~cpp
//主函数
int main()
{   
    Normal_Class dummy1;
    int size = sizeof(dummy1);

    int* pClass = reinterpret_cast<int*>(&dummy1);/*get ClassAddr*/
    int* pParam= &dummy1.param;/*get ParamAddr*/

    Funcpointer pFunc = &Normal_Class::testFunc;/*get FuncAddr*/

    cout << "This is ClassSize: " << size << endl;
    cout << "This is ClassAddr: " << pClass << endl;
    cout << "This is ParamAddr: " << pParam << endl;
    cout << "This is FuncAddr : " << &pFunc << endl;
    (dummy1.*pFunc)();/*Use FuncAddr to call this func*/

    return 0;
}
~~~

### 输出
> This is ClassSize: 4
This is ClassAddr: 0x61fe04
This is ParamAddr: 0x61fe04
This is FuncAddr : 0x61fdf0
testFunc is called!

可见实际输出与预期相符合。

### 内存结构模型
![1_Normal_Class](https://img-blog.csdnimg.cn/7eac4fbb686e4e11bb7dbf237f77b304.png#pic_center)

## 2.有继承的类对象
### 简介
在简单继承的情况下，子类将会把父类中的变量放在自己的变量之前。同样的，子类并不会将父类的成员函数以及自己的成员函数放在类当中。

### 代码
```cpp
//类定义
//父类
class BaseClass
{
public:
    int param_Base;
    void Func_Base()
    {
        cout << "BaseFunc is called!" << endl;
    }
};
//子类
class SubClass: public BaseClass
{
public:
    int param_Sub;
    void Func_Sub()
    {
        cout << "SubFunc is called!" << endl;
    }
};
```
```cpp
//主函数
typedef void (SubClass::*Funcptr)(void);

int main()
{
    SubClass dummy1;
    int size = sizeof(dummy1);

    int* pClass    = reinterpret_cast<int*>(&dummy1);
    int* pParam1   = &dummy1.param_Base;
    int* pParam2   = &dummy1.param_Sub;
    Funcptr pFunc1 = &SubClass::Func_Base;
    Funcptr pFunc2 = &SubClass::Func_Sub;

    cout << "This is ClassSize    : " << size << endl;
    cout << "This is ClassAddr    : " << pClass << endl;
    cout << "This is ParamAddrBase: " << pParam1 << endl;
    cout << "This is ParamAddrSub : " << pParam2 << endl;
    cout << "This is FuncAddrBase : " << &pFunc1 << endl;
    cout << "This is FuncAddrSub  : " << &pFunc2 << endl;

    (dummy1.*pFunc1)();
    (dummy1.*pFunc2)();

    return 0;
}
```

### 输出
> This is ClassSize    : 8
This is ClassAddr    : 0x61fdf8
This is ParamAddrBase: 0x61fdf8
This is ParamAddrSub : 0x61fdfc
This is FuncAddrBase : 0x61fde0
This is FuncAddrSub  : 0x61fdd0
BaseFunc is called!
SubFunc is called!

可见该对象的大小为8，代表父类的变量param_Base与子类的变量param_Sub大小之和。

### 内存结构模型
![2_Heritage_Class](https://img-blog.csdnimg.cn/b13fbd18762549bbac563e5d3d357308.png#pic_center)

## 3.有虚函数的类对象
### 简介
当成员函数中存在虚函数时，将会生成一个虚表，而类将会把虚表的地址存放在自己的地址开头几位。而程序是32位还是64位将会影响到虚表地址的长度。

### 代码
```cpp
//类定义
class vFuncClass
{
public:
    int param;
    void normalFunc()
    {
        cout << "normalFunc is called!" << endl;
    }

    virtual void virtualFunc()
    {
        cout << "virtualFunc is called!" << endl;
    }
};
```
```cpp
//主函数
typedef void (vFuncClass::*Funcptr)(void);

int main()
{
    vFuncClass dummy1;
    int size = sizeof(dummy1);

    intptr_t* pClass = (intptr_t*)(&dummy1);/*get vtable address's address*/
    intptr_t* pvtable  = (intptr_t*)(*pClass);/*get vtable address*/
    intptr_t  vFuncAddr= *pvtable;/*get vFunc address*/

    int* pParam   = &dummy1.param;
    Funcptr pFunc1 = &vFuncClass::normalFunc;

    cout << "This is vTableSize   : " << size << endl;
    cout << "This is vTableAddr   : " << pvtable << endl;
    cout << "This is ClassAddr    : " << pClass << endl;
    cout << "This is ParamAddr    : " << pParam << endl;
    cout << "This is FuncAddrNorm : " << &pFunc1 << endl;
    cout << "This is FuncAddrVirt : " << vFuncAddr << endl;

    (dummy1.*pFunc1)();
    ((void(*)(void))vFuncAddr)();/*call vFunc*/
    return 0;
}
```

### 输出
> This is vTableSize   : 16
This is vTableAddr   : 0x4045b0
This is ClassAddr    : 0x61fde0
This is ParamAddr    : 0x61fde8
This is FuncAddrNorm : 0x61fdd0
This is FuncAddrVirt : 4206272
normalFunc is called!
virtualFunc is called!

值得注意的是，用0x61fde8减去0x61fde0，可见虚表地址的大小长度为8个字节，而int类型变量param的大小是4个字节，那么该类的大小应当是12字节。可能是由于内存对齐，使该类的大小被扩大为16字节。

### 内存结构模型
![3_VirtualFunc_Class](https://img-blog.csdnimg.cn/2f3c9dbaef1c479db8243f4ab78ebd15.png#pic_center)

## 4.基类有虚函数的子类对象
### 简介
当子类继承了有虚函数的父类时，应当会同时继承其虚表。同样的，该虚表地址将会存放在类对象的开头几位地址处，同时后面紧跟父类中的成员变量指针。

### 代码
```cpp
//类定义
//父类
class vFuncClass
{
public:
    int param;
    void normalFunc()
    {
        cout << "normalFunc is called!" << endl;
    }

    virtual void virtualFunc()
    {
        cout << "virtualFunc is called!" << endl;
    }
};
//子类
class SubClass: public vFuncClass
{
public:
    int param2;
    void SubFunc()
    {
        cout << "SubFunc is called!" << endl;
    }
};
```
```cpp
//主函数
typedef void (SubClass::*Funcptr)(void);

int main()
{
    SubClass dummy1;
    int size = sizeof(dummy1);

    intptr_t* pClass = (intptr_t*)(&dummy1);/*get vtable address's address*/
    intptr_t* pvtable  = (intptr_t*)(*pClass);/*get vtable address*/
    intptr_t  vFuncAddr= *pvtable;/*get vFunc address*/

    int* pParam1   = &dummy1.param;
    int* pParam2   = &dummy1.param2;
    Funcptr pFunc1 = &SubClass::normalFunc;
    Funcptr pFunc2 = &SubClass::SubFunc;


    cout << "This is ClassSize    : " << size << endl;
    cout << "This is vTableAddr   : " << pvtable << endl;
    cout << "This is ClassAddr    : " << pClass << endl;
    cout << "This is ParamAddrBase: " << pParam1 << endl;
    cout << "This is ParamAddrSub : " << pParam2 << endl;
    cout << "This is FuncAddrSub  : " << &pFunc2 << endl;
    cout << "This is FuncAddrNorm : " << &pFunc1 << endl;
    cout << "This is FuncAddrVirt : " << vFuncAddr << endl;

    (dummy1.*pFunc2)();
    (dummy1.*pFunc1)();
    ((void(*)(void))vFuncAddr)();/*call vFunc*/
    return 0;
}
```

### 输出
>This is ClassSize   : 16      
This is vTableAddr   : 0x405640
This is ClassAddr    : 0x61fde0
This is ParamAddrBase: 0x61fde8
This is ParamAddrSub : 0x61fdec
This is FuncAddrSub  : 0x61fdc0
This is FuncAddrNorm : 0x61fdd0
This is FuncAddrVirt : 4206464
SubFunc is called!
normalFunc is called!
virtualFunc is called!

此时，子类中的结构顺序如下：虚表地址指针（8位），父类变量指针（4位），子类变量指针（4位）。

### 内存结构模型
![4_VirtualHeritageFunc1_Class](https://img-blog.csdnimg.cn/53d686393218460da16f97a1e9f23369.png#pic_center)

## 5.基类有虚函数且子类有自己的更多的虚函数的类对象
### 简介
理论上来说，仅仅增加虚函数并不会影响类对象的大小，但是会对虚表里的内容做出变化。

### 代码
```cpp
//类定义
//父类
class vFuncClass
{
public:
    int param;
    void normalFunc()
    {
        cout << "normalFunc is called!" << endl;
    }

    virtual void virtualFunc()
    {
        cout << "vFuncBase is called!" << endl;
    }
};
//子类
class SubClass: public vFuncClass
{
public:
    int param2;
    void SubFunc()
    {
        cout << "SubFunc is called!" << endl;
    }

    virtual void vFuncSub()
    {
        cout << "vFuncSub is called!" << endl;
    }
};
```

### 输出
> This is ClassSize    : 16
This is vTableAddr   : 0x405660
This is ClassAddr    : 0x61fdd0
This is ParamAddrBase: 0x61fdd8
This is ParamAddrSub : 0x61fddc
This is FuncAddrSub  : 0x61fdb0
This is FuncAddrNorm : 0x61fdc0
This is vBaseFuncAddr: 4206544
This is vBaseFuncAddr: 4206704
SubFunc is called!
normalFunc is called!
vFuncBase is called!
vFuncSub is called!

可见，只要获取了虚表的地址，就可以通过令虚表地址不断加1来实现对虚函数具体位置指针的遍历与虚函数的调用。

### 内存结构模型
![5_VirtualHeritageFunc2_Class](https://img-blog.csdnimg.cn/c7473509128b414ca5c112c3e5e760a1.png#pic_center)

## 6.多继承的类对象
### 简介
此例程中，子类继承了两个父类，获得了父类的成员变量。

### 代码
```cpp
//类定义
//父类1
class Base1
{
public:
    int bParam1;
    void bFunc1()
    {
        cout << "bFunc1 is called!" << endl;
    }
};
//父类2
class Base2
{
public:
    int bParam2;
    void bFunc2()
    {
        cout << "bFunc2 is called!" << endl;
    }
};
//子类
class Sub: public Base1, public Base2
{
public:
    int sParam;
    void sFunc()
    {
        cout << "sFunc is called!" << endl;
    }
};
```

### 输出
> This is ClassSize     : 12
This is ClassAddr     : 0x61fdec
This is ParamAddrBase1: 0x61fdec
This is ParamAddrBase2: 0x61fdf0
This is ParamAddrSub  : 0x61fdf4
This is FuncAddrBase1 : 0x61fdd0
This is FuncAddrBase2 : 0x61fdc0
This is FuncAddrSub   : 0x61fdb0
bFunc1 is called!
bFunc2 is called!
sFunc is called!

这时，系统似乎会根据继承的顺序来决定哪个父类的成员变量放在较前的位置。

### 内存结构模型
![6_MultiHeritage_Class](https://img-blog.csdnimg.cn/5368a78ffc4e4331964cd93a565bec4e.png#pic_center)

## 7.虚基类的类对象
### 简介
虚基类的使用可以有效防止继承时的二义性问题，保持结构的稳定。

### 代码
```cpp
//类定义
//顶层父类
class TOP
{
public:
    int topParam;
};
//中间父类1
class MIDDLE1: virtual public TOP
{
public:
    int mid1Param;
};
//中间父类1
class MIDDLE2: virtual public TOP
{
public:
    int mid2Param;
};
//子类
class BOTTOM: public MIDDLE1, public MIDDLE2
{
public:
    int botParam;
};
```
```cpp
//主函数
int main()
{
    BOTTOM dummy1;
    int size = sizeof(dummy1);
    int* pClass  = reinterpret_cast<int*>(&dummy1);
    int* pParam1 = &dummy1.MIDDLE1::topParam;
    int* pParam2 = &dummy1.MIDDLE2::topParam;
    int* pParam3 = &dummy1.botParam;

    cout << "This is ClassSize          : " << size << endl;
    cout << "This is ClassAddr          : " << pClass << endl;
    cout << "This is Param_Mid-Top1_Addr: " << pParam1 << endl;
    cout << "This is Param_Mid-Top2_Addr: " << pParam2 << endl;
    cout << "This is Param_Bot_Addr     : " << pParam3 << endl;

    return 0;
}
```

### 输出
> This is ClassSize          : 40
This is ClassAddr          : 0x61fdd0
This is Param_Mid-Top1_Addr: 0x61fdf0
This is Param_Mid-Top2_Addr: 0x61fdf0
This is Param_Bot_Addr     : 0x61fdec

可见两个中间层父类对象的首地址皆为同一个顶层父对象的成员变量，这说明在此继承过程中只产生了一个顶层父类对象。若不使用虚基类，则将会出现两个不同的顶层父类对象。
### 内存结构模型
![7_vBase_Class](https://img-blog.csdnimg.cn/92e0dae58c5948b59d9b86ff9c557991.png#pic_center)

