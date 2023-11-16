# 基类有虚函数且子类还有自己的虚函数对象
```C++
#include <iostream>
using namespace std;
class animal
{
    public:
    virtual void speak()
    {
        cout<< "动物在说话" << endl;
    }
    virtual void run()
    {
        cout <<"动物在跑步" << endl;
    } 
    int age;
};
class dog:public animal
{
    public:
    void speak()
    {
        cout << "小狗在说话" <<endl;
    }
    virtual void dog_run()
    {
        cout <<"小狗在跑步" << endl;
    }
};
int main()
{   
    dog lv;
    animal dw;
    cout << sizeof(lv) << endl;//64位操作，8个字节的指针
    cout << sizeof(dw) << endl;
    cout << sizeof(intptr_t) << endl;
    cout << (intptr_t*)&dw << endl;//  类对象地址，取出前8个字节
    cout << (intptr_t *)&lv << endl; //两个地址不一样

    intptr_t *dog1 = (intptr_t *)*(intptr_t *)&lv;
    intptr_t *dw1 = ((intptr_t *)*(intptr_t *)&dw);//利用指针+1 完美
    cout << "---------------------------" << endl;
    cout << "动物类： " << endl;
    cout << (dw1) << endl;
    cout << (dw1+1) << endl;
    ((void(*)(void))*dw1)(); 
    ((void (*)(void)) * (dw1+1))();

    cout << "--------------------------" << endl;
    cout << " 狗类：" << endl;
    cout << (dog1) << endl;
    cout << (dog1 + 1) << endl;//对于函数地址好像不用解，这样来看就相差8，指针
    ((void (*)()) * (dog1))();
    ((void (*)()) * (dog1 + 1))(); // 第一个位返回类型，第二个位形参类型可不写，最后一个为函数参数
    ((void (*)()) * (dog1 + 2))();
    cout << endl;

    lv.speak();
    lv.run();
    lv.dog_run();
    return 0;
}
```
狗类对象：
|vfptr|
|--|
age

vftable|
|--|
dog::speak
animal::run
dog::dog_run

# 多继承的类对象
```C++
#include <iostream>
#include <string>
using namespace std;

class Houce
{
    public:
    virtual void houce_speak() 
    {
        cout << "马叫" << endl;
    }
    virtual void houce_run()
    {
        cout << "马跑" << endl;
    }
    virtual void houce_eat()
    {
        cout << "马吃" << endl;
    }
};
class Donkey
{
    public:
    virtual void donkey_speak()
    {
        cout << "驴叫" << endl;
    }
    virtual void donkey_run()
    {
        cout << "驴跑" << endl;
    }


};
class Mule:public Houce, public Donkey
{
    public:
        virtual void houce_speak()
        {
        cout << "骡子学马叫" << endl;
        }
        virtual void donkey_speak()
        {
            cout <<"骡子学驴叫" << endl;
        }
        virtual void mule_speak()
        {
            cout <<  "骡子自己说话" << endl;
        }
};
int main()
{
    Houce houce1;
    Donkey donkey1;
    Mule mule1;
    cout << "对象大小" << endl;
    cout << sizeof(Houce) << endl;
    cout << sizeof(Donkey) << endl;
    cout << sizeof(Mule) << endl;  //2个vfptr

    cout << "对象地址 第一个vfptr" << endl;
    cout << (intptr_t*)&houce1 << endl;
    cout << (intptr_t *)&donkey1 << endl;
    cout << (intptr_t *)&mule1<< endl;//类对象地址，也就是第一个vfptr
    cout << ((intptr_t *)&mule1 + 1) << endl;//第二个vfptr
    cout << endl;

    cout << "虚函数表地址" << endl;
    cout << (intptr_t *)*(intptr_t *)&houce1 << endl;
    cout << (intptr_t *)*(intptr_t *)&donkey1 << endl;
    cout << (intptr_t *)*(intptr_t *)&mule1 << endl;//虚函数表地址，第一个指针所指
    cout << (intptr_t *)*((intptr_t *)&mule1+1) << endl;//第二个指针所指的函数表
    cout << endl;

    intptr_t *mule_p = (intptr_t *)*(intptr_t *)&mule1;
    intptr_t *mule_p2 = (intptr_t *)*((intptr_t *)&mule1+1);//第二个指针

    cout << "第一个虚函数表" << endl;
    ((void(*)())*mule_p)();
    ((void (*)()) * (mule_p+1))();
    ((void (*)()) * (mule_p+2))();//重写了骡子学驴叫
    ((void (*)()) * (mule_p + 3))();
    ((void (*)()) * (mule_p + 4))();
    ((void (*)()) * (mule_p + 7))();//虚函数表地址+6得到第二个虚函数表地址  刚好是相差6个8，4个函数+offset_to_top,type_inf
    ((void (*)()) * (mule_p + 8))(); // 虚函数表地址+6得到第二个虚函数表地址
    cout << endl;

    cout << "第二个虚函数表" << endl;
    ((void (*)()) * mule_p2)();
    ((void (*)()) * (mule_p2 + 1))();
    //((void (*)()) * (mule_p2 + 2))();
    cout << endl;

    Houce *p = &mule1;
    cout << "------------------------------------" << endl;
    p->houce_speak();
    p->houce_run();
    mule1.donkey_speak();
    mule1.mule_speak();

    return 0;
}
```
骡类对象:
|vfptr|
|--|
|vfptr|

vftable1|
--|
mule:: houce_speak()|
houce:: houce_run()|
houce:: houce_eat()|
mule:: donkey_speak()|
mule:: mule_speak()|

vftable2|
--|
mule:: donkey_speak()|
donkey:: donkey_run()

# 基类和子类都带有虚函数的菱形继承对象

```C++
#include <iostream>
#include <string>
using namespace std;
class Animal
{
public:
    int animal_a;
    virtual void animal_speak()
    {
        cout << "动物说话" << endl;
    }
    virtual void animal_run()
    {
        cout << "动物跑步" << endl;
    }
};
class Sheep : virtual public Animal
{
public:
    virtual void sheep_speak()
    {
        cout << "羊在说话" << endl;
    }
    virtual void sheep_run()
    {
        cout << "羊在运动" << endl;
    }
    //int sheep_b;
};
class Tuo : virtual public Animal
{
public:
    virtual void tuo_speak()
    {
        cout << "驼在说话" <<endl;
    }
    //int tuo_c;
};
class Sheeptuo : public Sheep, public Tuo
{
public:
    virtual void animal_speak()
    {
        cout << "羊驼在学动物说话" << endl;
    }
    virtual void sheep_speak()
    {
        cout << "羊驼在学羊说话" << endl;
    }
    virtual void sheeptuo_run()
    {
        cout << "羊驼在运动" << endl;
    }
    int sheeptuo_d;

};
int main()
{
    Sheeptuo yt1;
    cout << sizeof(yt1) << endl;
    cout << (intptr_t*)&yt1 << endl;
    cout << (intptr_t *)*(intptr_t *)&yt1 << endl;//第一个指针
    intptr_t *yt_p1 = (intptr_t *)*(intptr_t *)&yt1;
    cout << "使用第一个vfptr" << endl;
    ((void (*)()) * (yt_p1))();
    ((void (*)()) * (yt_p1+1))();
    ((void (*)()) * (yt_p1+2))();
    ((void (*)()) * (yt_p1+3))();
    cout << endl;

    intptr_t *yt_p2 = (intptr_t *)*((intptr_t *)&yt1+1);
    cout << "使用第二个vfptr" << endl;
    ((void (*)()) * (yt_p2))();
    cout << endl;

    // intptr_t *yt_p3 = (intptr_t *)*((intptr_t *)&yt1 + 6);
    // cout << "使用第三个vfptr" << endl;
    // ((void (*)()) * (yt_p3))();
    // cout << endl;

    return 0;
};
```
羊驼对象模型|
--|
vfptr1
sheep:: sheep_b
vfptr2
tuo:: tuo_c
sheeptuo:: sheeptuo_d
vfptr3
animal:: animal_a

vfptr1|
--|
sheeptuo:: sheep_speak()
sheep:: sheep_run()
sheeptuo:: animal_speak()
sheep:: sheeptuo_run()

vfptr2|
--|
tuo:: tuo_speak()

## 第三个指针未验证成功！！！







