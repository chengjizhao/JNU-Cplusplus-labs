## 一般类对象

一般类对象就是普通对象，对象成员可以分为两类：成员函数和成员属性。

这些成员在内存中的存放方式如下：

- 成员函数存放在代码区，其它所有成员函数地址通过编译器获取；
- 静态成员变量存放在静态存储区；
- 普通成员变量存放在对象内，遵循字节对齐原则存放。

![img](https://pic3.zhimg.com/80/v2-82e4b1eba6eb3f3df7daf2eae3372de6_720w.webp)

编程验证如下

```c++
#include <iostream>
#include <cstdio>
using namespace std;
class A{
private:
    char a;
public:
    int b;
    char c;
    void func() {
        cout << "this's a function."<<endl;
    }
};
int main(int argc, char** argv){
    cout << sizeof(A) << endl; /*12*/
    A obj;
    /*000000000061fe18 000000000061fe1c*/
    printf("%p %p \n",&obj.b, &obj.c);
    return 0;
}
```



## 继承类对象(非虚继承)

子类会继承父类的对象成员，包括成员函数和成员变量，继承后的子类对象内存模型和一般类对象一样

| **继承方式/基类成员** | public成员 | **protected成员** | private成员 |
| --------------------- | ---------- | ----------------- | ----------- |
| **public继承**        | public     | protected         | 不可见      |
| **protected继承**     | protected  | protected         | 不可见      |
| **private继承**       | private    | private           | 不可见      |

>需要注意的是：
>
>由上表，基类的 private 成员不能在派生类中使用，并没有说基类的 private 成员不能被继承。实际上，基类的 private 成员是能够被继承的，并且（成员变量）会占用派生类对象的内存，它只是在派生类中不可见，导致无法使用罢了。private 成员的这种特性，能够很好的对派生类隐藏基类的实现，以体现面向对象的封装性。由于 private 和 protected 继承方式会改变基类成员在派生类中的访问权限，导致继承关系复杂，所以实际开发中我们一般使用 public。

验证代码如下：

```c++
#include <iostream>
#include <cstdio>
using namespace std;

class foo1{
private:
    char a;
public:
    int b;
    char c;
};
class foo2 : public foo1{
public:
    /*
    char a;
    int b;
    char c;
    */
    short d;
    char e;
};
int main(int argc, char** argv){
    cout << sizeof(foo1) << endl; /*12*/
    cout << sizeof(foo2) << endl; /*16*/
    foo2 obj;
    /*000000000061fe14 000000000061fe18 000000000061fe1a 000000000061fe1c*/
    printf("%p %p %p %p \n", &obj.b, &obj.c, &obj.d, &obj.e);
    return 0;
}
```

## 带虚函数的类对象

带有虚函数的类对象的内存模型涉及到虚函数表（Virtual Function Table，简称VTable）和虚指针。下面是一个简要的说明：

![image-20240102105501365](https://c.biancheng.net/uploads/allimg/180831/1-1PS1111S0Q6.jpg)

1. **虚函数表（VTable）**：

   - 对于包含虚函数的类，编译器会生成一个虚函数表，存储在全局静态存储区。
   - 虚函数表是一个数组，存储了类中所有虚函数的地址（代码段）。
   - 对象的内存布局中通常包含一个指向虚函数表的指针（虚指针）。

2. **虚指针**：

   - 每个包含虚函数的类的对象都有一个虚指针, 在对象内存的最前面。
   - 虚指针指向该类的虚函数表的起始地址。

3. **内存布局编程验证**

   ```c++
   #include <iostream>
   using namespace std;
   class A{
   public:
       int data;
       void func() {
           cout << "this's a function."<<endl;
       }
   };
   class B{
   public:
       int data;
       virtual void func() {
           cout << "this's a virtual function."<<endl;
       }
   };
   int main(int argc, char** argv){
       cout << "sizeof(A): " <<sizeof(A) << endl; /*4*/
       cout << "sizeof(B): " <<sizeof(B) << endl; /*16*/
       //通过虚函数表获取函数指针
       B obj_B;
       void** VTablePtr =*reinterpret_cast<void***>(&obj_B);
       void (*funcPtr)();
       funcPtr = reinterpret_cast<void(*)()>(VTablePtr[0]);
       (*funcPtr)();
       return 0;
   }
   ```

   - 结果

   ```txt
   sizeof(A): 4
   sizeof(B): 16
   this's a virtual function.
   ```

## 基类有虚函数的子类对象

子类继承父类后，有自己的一张虚函数表，也是存在全局静态区。子类的虚函数表包含了父类的虚函数表，未重写的函数指向父类的对应函数。

如图：

![img](https://pic4.zhimg.com/v2-c2e3f40ad2c21744af3362e29b99bb4f_r.jpg)

编程验证：

```c++
#include <iostream>
using namespace std;
class A{
public:
    int data;
    virtual void func1() {
        cout << "this's a virtual function."<<endl;
    }
    virtual void func2() {
        cout << "called by A."<<endl;
    }
};
class B : public A{
public:
    void func2() override{
        cout << "called by B."<<endl;
    }
};
class C : public A{
public:
    void func2() override{
        cout << "called by C."<<endl;
    }
};
int main(int argc, char** argv){
    A* objA = new A();
    B* objB = new B();
    C* objC = new C();
//  获取虚函数指针
    void** vTableA = *reinterpret_cast<void***>(objA);
    void** vTableB = *reinterpret_cast<void***>(objB);
    void** vTableC = *reinterpret_cast<void***>(objC);
    cout<<"A::func1's adrress: "<< vTableA[0]<<endl;
    cout<<"A::func2's adrress: "<< vTableA[1]<<endl;
    cout<<"B::func1's adrress: "<< vTableB[0]<<endl;
    cout<<"B::func1's adrress: "<< vTableB[1]<<endl;
    cout<<"C::func1's adrress: "<< vTableC[0]<<endl;
    cout<<"C::func1's adrress: "<< vTableC[1]<<endl;
    return 0;
}
```

输出结果为：

```
A::func1's adrress: 0x402eb0
A::func2's adrress: 0x402ef0
B::func1's adrress: 0x402eb0
B::func2's adrress: 0x402f70
C::func1's adrress: 0x402eb0
C::func2's adrress: 0x402fe0
```

可以看出，B和C对func2重写了，没有重写func1，所以func1的地址和A是一样的，func2的地址和A的不一样。

## 基类有虚函数且子类有自己的更多的虚函数的类对象

基类有虚函数且子类有自己的更多的虚函数的类对象：这种情况下，子类会在虚函数表中追加自己新增的虚函数的地址。对象的内存模型中会包含指向虚函数表的指针，并且虚函数表的最后一部分是子类新增的虚函数。和前面的模型基本上是一样的

编程验证：

```c++
#include <iostream>
using namespace std;
class A{
public:
    int data;
    virtual void func2() {
        cout << "called by A."<<endl;
    }
};
class B : public A{
public:
    virtual void func1() {
        cout << "this's a virtual function."<<endl;
    }

};
int main(int argc, char** argv){
    A* objA = new A();
    B* objB = new B();
//  获取虚函数指针
    void** vTableA = *reinterpret_cast<void***>(objA);
    void** vTableB = *reinterpret_cast<void***>(objB);
    cout<<"A::func2's adrress: "<< vTableA[0]<<endl;
    cout<<"B::func1's adrress: "<< vTableB[0]<<endl;
    cout<<"B::func2's adrress: "<< vTableB[1]<<endl;
    return 0;
}
```

输出：

```
A::func2's adrress: 0x402dd0
B::func1's adrress: 0x402dd0
B::func2's adrress: 0x402e50
```

## 多继承的类对象

多继承的类对象包含多个基类的成员变量和成员函数。内存布局中，不同基类的成员变量按照它们在派生类中声明的顺序排列。

编程证明：

```c++
#include<iostream>
using namespace std;
class Base1{
public:
    int a;
    int b;
    void func(){

    }
};
class Base2{
public:
    int a;
    int c;
    void func(){

    }
};
class Device : public Base1, public Base2{
public:
    int d;
    void func(){

    }
};
int main(){
    cout<<"sizeof(Base1): "<<sizeof(Base1)<<endl;
    cout<<"sizeof(Base2): "<<sizeof(Base2)<<endl;
    cout<<"sizeof(Device): "<<sizeof(Device)<<endl;
    return 0;
}
```

输出：

```
sizeof(Base1): 8
sizeof(Base2): 8
sizeof(Device): 20
```

当多继承类对象有虚函数时，模型如下图：

![](https://img-blog.csdnimg.cn/20210318164833911.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L01hc3Rlcl9DdWk=,size_16,color_FFFFFF,t_70)

## 虚基类的类对象

g++中是没有所谓的虚基类表的（vs是有单独一个虚基类表的），只有一个虚表，由于平时用的比较多的是虚函数，所以一般情况下都直接管它叫做虚函数表,gcc编译器下内存布局如图

<img src="https://img-blog.csdnimg.cn/20210630211127468.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80Mzc5ODg4Nw==,size_16,color_FFFFFF,t_70#pic_center" style="zoom:67%;" />

对应代码：

```c++
#include <iostream>
#include <stdint.h>

class A
{
public:
    long a;
};

class B: virtual public A
{
public:
    long b;
};

class C: virtual public A
{
public:
    long c;
};

class D: public B, public C
{
public:
    void seta(long v) { a = v; }
    void setb(long v) { b = v; }
    void setc(long v) { c = v; }
    void setd(long v) { d = v; }

private:
    long d;
};

int main(int argc, char* argv[])
{
    D d;
    d.seta(1);
    d.setb(2);
    d.setc(3);
    d.setd(4);
}
```

