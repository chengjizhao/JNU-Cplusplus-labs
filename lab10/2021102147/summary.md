# C++ 对象的内存模型

## 一般对象和子类对象

### 说明
一般对象的内存中仅包含其成员变量而不包含成员函数，子类对象中包括父类的成员变量和
子类自己的成员变量。

### 代码验证
```cpp
// SampleClass.h
class SampleClass
{
public:
	int getNum()const;
	int pnum;
private:
	int num;
};

class SampleClassExtend : public SampleClass
{
public:
	int getExNum()const;
	int expnum;
private:
	int exnum;
};
```

```cpp
// main.cpp
#include "SampleClass.h"

#include <iostream>

int main() {
	SampleClass sc;
	SampleClassExtend sce;
	std::cout << sizeof(sc) << std::endl;
	std::cout << sizeof(sce) << std::endl;
	return 0;
}
```

控制台输出：

> 8 
>
> 16

父类对象有2个整型成员变量，因此占`4 * 2 = 8`个字节。子类对象也包含2个整型成员变量，
共占用`4 * 2 + 8 = 16`个字节。

## 有虚函数的类对象及其子类对象，以及覆盖了父类的虚函数的子类对象

### 说明
虚函数的实现要通过虚函数表，因此有虚函数的类对象应当包含一个虚函数表指针
（在64位操作系统上是8字节）。同理，其子类也包括一个虚函数表指针。

虚函数表的特征如下
- 若子类没有覆盖父类的虚函数，则子类和父类共用同一个虚函数表。
- 若子类覆盖了任意一个父类的虚函数，或者子类定义了新的虚函数，那么子类将拥有自己的虚函数表，
其中对应的函数指针被覆盖。其它成员和普通的类对象及其子类对象一致。

### 验证代码和环境

```cpp
// SampleClass.h
class SampleClass
{
public:
	virtual void VirtualMethod();
	virtual void VirtualMethod2();
private:
	char num = 0;
};

class SampleClassExtend : public SampleClass
{
public:
	virtual void VirtualMethod();
	virtual void ExtraVirtualMethod();
private:
	int num2 = 0;
	int num3 = 0;
};

class SampleClassExtend2 : public SampleClass
{

};
```
注：以上各成员函数的定义在此省略不写。

```cpp
// main.cpp
#include "SampleClass.h"

int main()
{
	SampleClass sc;
	SampleClassExtend sce;
	SampleClassExtend2 sce2;
	
	sc.VirtualMethod();
	sce.VirtualMethod();
	sce.ExtraVirtualMethod();
	sce2.VirtualMethod();
	return 0;
}
```

> 环境：
>
> Windows 11 22H2 x64 with Intel Core i5-11300H
>
> 编译器：
>
> g++ 13.1.0

### 内存占用验证
通过sizeof获取SampleClass、SampleClassExtend、SampleClassExtend2的大小，得到
> 16
>
> 24
>
> 16

这里涉及到一个内存对齐的问题（可能）。如果对象的实际占用不是8的倍数，会被自动填充为8的
倍数。例如SampleClassExtend的实际大小为`8 + 2 * 4 + 1 = 17`，被填充为24。

### 虚函数表验证
我个人强烈反对使用指针转换符对指针进行各类乱七八糟、甚至是非法的转换，更不要说拿这种指针
来当作函数指针以试图调用某个函数了。这样做很可能让人染上滥用指针类型转换的毛病。因此，
不通过所谓取指针打印的方法，而通过反汇编的方法直接查看内存来得到结论。

使用x64dbg调试编译出来的二进制程序test.exe，发现直接查看汇编代码比较难懂，
于是先使用ida反汇编，来对照实际的汇编代码。

如图，左图为x64dbg的截图，右图为ida的截图。重要的语句已经用黄色记号标出。

![汇编代码](https://cdn.ncmc.me/2023/11/00/00.jpg)

标黄的语句中，第一第二句分别获取SampleClass和它的子类SampleClassExtended的虚函数表地址。

对照我们的源代码可以看出，第4-6句分别调用了父类的虚函数、 子类覆盖的虚函数、 子类新定义的虚函数
子类未覆盖的虚函数。

从第一、二句可以看出，程序只加载了SampleClass和SampleClassExtend的虚函数表。
对比第四句和第六句，可以看出执行的实际上是同一个函数`SampleClass::VirtualMethod`，因此
得出结论一：若子类未覆盖任何虚函数，则和父类共用同一个虚函数表，且执行父类的虚函数。

对照汇编代码和结论一即可得到结论二：覆盖了父类虚函数的子类对象拥有自己的虚函数表。

下面来验证被执行的四个函数确实是通过虚函数表查出来的。对照x64dbg提供的汇编代码，我们知道，
SampleClass的虚函数表地址为：`ds:[7FF7B08D4440] + 10h`，SampleClassExtend的虚函数表
地址为：`ds:[7FF7B08D4450] + 10h`。使用内置的计算器计算出实际的地址并跳转到对应内存。

![计算器](https://cdn.ncmc.me/2023/11/00/01.jpg)
![计算器](https://cdn.ncmc.me/2023/11/00/02.jpg)
![内存](https://cdn.ncmc.me/2023/11/00/03.jpg)

内存图中，每行包含16个字节，因此可以存储两个指针，可以看出SampleClass包括两个虚函数。
Intel处理器使用[小端序](https://zh.wikipedia.org/zh-cn/%E5%AD%97%E8%8A%82%E5%BA%8F) ，据此可以读出第一个虚函数的地址为`7FF7B08D1450`，与
代码中显示的完全一致。其它三个函数可以如法炮制，就不画蛇添足了。这里也可以看出
SampleClassExtend有三个虚函数，没覆盖的父类虚函数指针原样保存在虚函数表中。

## 多继承和虚继承
马克思主义认为，要结合理论和实践，实践可以推动理论。
因此，让我们从事实来推出理论。

编写以下代码
```cpp
// SampleClass.h

class SampleClass
{
public:
	virtual void VirtualMethod();
	virtual void VirtualMethod2();
private:
	char num = 1;
};


class SampleClassExtend1 : virtual public SampleClass
{
public:
	virtual void VirtualMethod();
private:
	int n = 2147483647;
};

class SampleClassExtend2 : virtual public SampleClass
{
private:
	double d = 3;
};

class SampleClassExtendExtend : public SampleClassExtend1, public SampleClassExtend2
{
private:
	long long ll = 100;
};

class normalExtend : public SampleClass
{
private:
	long long ll = -1;
};
```

```cpp
// main.cpp
#include "SampleClass.h"

int main()
{
	SampleClass sc;
	SampleClassExtend1 sce1;
	SampleClassExtendExtend scee;
	normalExtend ne;
	return 0;
}
```
编译以上代码，使用x64dbg调试，直接找到sc、sce1、scee的地址并转到内存，如下图
![内存](https://cdn.ncmc.me/2023/11/00/04.jpg)
三个对象的内存已经用红线分开，**从下到上**分别为sc、sce1、scee

sc的内容：
- 7ff69ba34820 这是SampleClass第一个虚函数的地址
- ..........01 这是sc的数据，前面的是内存中的残余随机数据

sce1的内容：
- 7ff6b9a34890 这是SampleClassExtend1覆盖了的虚函数（VirtualMethod）的地址
- ..........01 这是从父类继承来的数据
- 7ff6b9a34868 等价于上面结尾为4890的地址
- ....7fffffff int 类型的2147483647，是sce1的数据

scee的内容：
- 7ff69ba348f8 等价于上面结尾为4890的地址
- ..........01 SampleClass继承来的数据

- 7ff69ba348d8 未知内容，此为非法地址
- 000000000064 long long类型的100，scee自己的数据

- 7ff69ba348b8 等价于上面结尾为4890的地址
- ....7fffffff 从sce1继承来的数据

由此我们可以大致得到结论。

并非如我们所想，对象包含的指针中并没有指向我们的虚函数表，而是直接指向了函数的入口，或许
这是编译器优化导致的。其它的并无特殊，和普通的继承类似。