#include <iostream>
using namespace std;

class Car
{
public:
    virtual void price()
    {
        cout << "父类虚函数1" << endl;
    }
    virtual void price2()
    {
        cout << "父类虚函数2" << endl;
    }
};

class Sedan : public Car
{
public:
    void price() override
    {
        cout << "调用子类1虚函数" << endl;
    }
};

class SUV : public Car
{
public:
    void price() override
    {
        cout << "调用子类2虚函数" << endl;
    }
};
int main()
{
    Car car;
    Car car2;
    void (Car::*Pcar1)();
    Pcar1 = &Car::price;
    void (Car::*Pcar2)();
    Pcar2 = &Car::price2;

    SUV suv;
    void (SUV::*Psuv1)();
    Psuv1 = &SUV::price;
    void (SUV::*Psuv2)();
    Psuv2 = &SUV::price2;

    Sedan sedan;
    void (Sedan::*Psedan1)();
    Psedan1 = &Sedan::price;
    void (Sedan::*Psedan2)();
    Psedan2 = &Sedan::price2;

    cout << "父类对象car1虚函数price的虚函数地址：" << reinterpret_cast<void *>(car.*Pcar1) << endl;
    cout << "父类对象car1虚函数price2的虚函数地址：" << reinterpret_cast<void *>(car.*Pcar2) << endl;
    cout << "父类对象car2虚函数price的虚函数地址：" << reinterpret_cast<void *>(car2.*Pcar1) << endl;
    cout << "父类对象car2虚函数price2的虚函数地址：" << reinterpret_cast<void *>(car2.*Pcar2) << endl;
    cout << "子类对象1 覆盖了父类虚函数price的虚函数地址：" << reinterpret_cast<void *>(suv.*Psuv1) << endl;
    cout << "子类对象1 没有覆盖父类虚函数price2的虚函数地址：" << reinterpret_cast<void *>(suv.*Psuv2) << endl;
    cout << "子类对象2 覆盖了父类虚函数price的虚函数地址：" << reinterpret_cast<void *>(sedan.*Psedan1) << endl;
    cout << "子类对象2 没有覆盖父类虚函数price2的虚函数地址：" << reinterpret_cast<void *>(sedan.*Psedan2) << endl;
    return 0;
}

/*
从运行结果得：
1.若子类没有覆盖父类的虚函数，其虚函数地址与父类相同，共用一个虚函数表
若子类覆盖了任何父类的虚函数，则那个覆盖的虚函数的地址变为新的地址，
即另用一个虚函数表，其它没有覆盖的虚函数仍和父类相同

2.多个子类对象没覆盖过父类函数的虚函数，跟父类函数的那个虚函数指向同一个表
多个子类对象使用同一个类内虚函数，指向同一个表。
*/