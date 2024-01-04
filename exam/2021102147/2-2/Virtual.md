# 虚指针
虚指针是指向虚函数表的指针。这个指针位于对象内存空间的开头，指向内存中虚函数表的首地址。

# 额外信息
一个类包含虚函数，则其头部有一个虚指针指向虚函数表，表中存放要被执行的虚函数代码。


# 演示
```
// SampleClass.h

class Implement;

class Abstract
{
private:
	Implement imp;
};

class Implement
{
public:
	virtual void foo() = 0;
};

class Implement_Ex1 : public Implement
{
public:
	virtual void foo();
};

class Implement_Ex2 : public Implement
{
public:
	virtual void foo();
}
```
如以上代码，使用桥模式定义了两个子类，通过虚函数的方式继承并实现父类的函数foo，从而达到抽象解耦的效果。