#include <iostream>

using namespace std;
using FUNC = void (*)();

class Base1
{
    public:
        int a1;
        void fun1() {cout << "Base::fun1()" << endl;}
};

class Derived2 : public Base1
{
    public:
        int a2;
        void fun2() {cout << "Derived::fun2()" << endl;}
};

class Base3
{
    public:
        int a3;
        virtual void fun3() {cout << "Base::fun3()" << endl;}
};

class Derived4 : public Base3
{
    public:
        int a4;
        virtual void fun4() {cout << "Derived::fun4()" << endl;}
};

class Base5
{
    public:
        int a5_1;
        virtual void fun5_1() {cout << "Base::fun5_1()" << endl;}
        virtual void fun5_2() {cout << "Base::fun5_2()" << endl;}
};

class Derived5 : public Base5
{
    public:
        int a5_2;
        void fun5_1() override {cout << "Derived::fun5_1()" << endl;}
        virtual void fun5_3() {cout << "Derived::fun5_3()" << endl;}
};

class Base6_1
{
    public:
        int a6_1;
        void fun6_1() {cout << "Base::fun6_1()" << endl;}
};

class Base6_2
{
    public:
        int a6_2;
        void fun6_2() {cout << "Base::fun6_2()" << endl;}
};

class Derived6_3 : public Base6_1, public Base6_2
{
    public:
        int a6_3;
        void fun6_3() {cout << "Derived::fun6_3()" << endl;}
};

class Base7
{
    public:
        int a7_1;
};

class Derived7 : virtual public Base7
{
    public:
        int a7_2;
};

int main()
{
    // 一般类对象
    cout << "\n" << "----------" << endl;
    Base1 n1;
    cout << &n1 << endl;
    cout << &n1.a1 << endl;
    n1.fun1();

    // 继承类对象
    cout << "\n" << "----------" << endl;
    Derived2 n2;
    cout << &n2 << endl;
    cout << &n2.a1 << endl;
    cout << &n2.a2 << endl;
    n2.fun1();
    n2.fun2();

    // 带虚函数的类对象
    cout << "\n" << "----------" << endl;
    Base3 *n3 = new Base3();
    auto *tmp3 = (long long *) n3;
    auto *vptr3 = (long long *) (*tmp3);
    FUNC fun3 = (FUNC) *vptr3;
    cout << &*n3 << endl;
    cout << &n3->a3 << endl;
    n3->fun3();
    fun3();

    // 基类有虚函数的子类对象
    cout << "\n" << "----------" << endl;
    Derived4 *n4 = new Derived4();
    auto *tmp4 = (long long *) n4;
    auto *vptr4 = (long long *) (*tmp4);
    FUNC fun4_1 = (FUNC) *vptr4;
    FUNC fun4_2 = (FUNC) *(vptr4 + 1);
    cout << &*n4 << endl;
    cout << &n4->a3 << endl;
    cout << &n4->a4 << endl;
    n4->fun3();
    n4->fun4();
    fun4_1();
    fun4_2();

    // 基类有虚函数且子类有自己的更多的虚函数的类对象
    cout << "\n" << "----------" << endl;
    Derived5 *n5 = new Derived5();
    auto *tmp5 = (long long *) n5;
    auto *vptr5 = (long long *) (*tmp5);
    FUNC fun5_1 = (FUNC) *vptr5;
    FUNC fun5_2 = (FUNC) *(vptr5 + 1);
    FUNC fun5_3 = (FUNC) *(vptr5 + 2);
    cout << &*n5 << endl;
    cout << &n5->a5_1 << endl;
    cout << &n5->a5_2 << endl;
    n5->fun5_1();
    n5->fun5_2();
    n5->fun5_3();
    fun5_1();
    fun5_2();
    fun5_3();

    // 多继承的类对象
    cout << "\n" << "----------" << endl;
    Derived6_3 n6;
    cout << &n6 << endl;
    cout << &n6.a6_1 << endl;
    cout << &n6.a6_2 << endl;
    cout << &n6.a6_3 << endl;
    n6.fun6_1();
    n6.fun6_2();
    n6.fun6_3();

    // 虚基类的类对象
    cout << "\n" << "----------" << endl;
    Derived7 n7;
    cout << &n7 << endl;
    cout << &n7.a7_1 << endl;
    cout << &n7.a7_2 << endl;

    return 0;
}