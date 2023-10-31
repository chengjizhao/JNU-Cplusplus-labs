#include <iostream>

using namespace std;

//父类中包含两个虚函数,其中第二个会在子类中override
class Father
{
private:
public:
    virtual void Const_Func()
    {}

    virtual void Target()
    {cout << "this is father's virtual func." << endl;}

};

//该子类对父类无修改
class Son_NO_override: public Father
{
private:
public:

};

//该子类override了第二个虚函数
class Son_override: public Father
{
private:
public:
    void Target() override
    {cout << "this is son's override func" << endl;}

};


int main()
{
    Father father1;
    Father father2;
    Son_NO_override son1;
    Son_override son2;


    //用int会报 "cast to pointer from integer of different size" 警告,可能是int不够大,故使用long long
    long long vtablAdd1 = *(long long*)(&father1);              //vtable的地址
    long long* temp = (long long*)vtablAdd1;                    //vtalbe的地址放入指针
    long long vfuncAdd1 = *temp;                                //取出vtable地址首位存放的东西(func1的地址)
    long long vfuncAdd12 = *(temp+1);                           //func1加一偏移值得到func2的地址

    long long vtablAdd2 = *(long long*)(&father2);           
    temp = (long long*)vtablAdd2;                   
    long long vfuncAdd2 = *temp;  
    long long vfuncAdd22 = *(temp+1);

    long long vtablAdd3 = *(long long*)(&son1);           
    temp = (long long*)vtablAdd3;                   
    long long vfuncAdd3 = *temp;  
    long long vfuncAdd32 = *(temp+1);

    long long vtablAdd4 = *(long long*)(&son2);                  
    temp = (long long*)vtablAdd4;                 
    long long vfuncAdd4 = *temp; 
    long long vfuncAdd42 = *(temp+1);
    
    //发现用同一个class实例化的对象有着同一个vtable.
    cout << "father1's vtable address is: " << vtablAdd1 << endl;
    cout << "father2's vtable address is: " << vtablAdd2 << endl;
    cout << "son1's vtable address is: " << vtablAdd3 << endl;
    cout << "son2's vtable address is: " << vtablAdd4 << endl;
    cout << "可见用同一个类实例化的对象有着同一个vtable,其子类实例化的对象(无论是否override)都会改变vtable的地址." << endl << endl;

    //此处打印了四个对象的第一个虚函数的地址,该虚函数是没有被override的.发现子类与父类的虚函数地址一致.
    cout << "father1's first virtual Func's address is: " << vfuncAdd1 << endl;
    cout << "father2's first virtual Func's address is: " << vfuncAdd2 << endl;
    cout << "son1's first virtual Func's address is: " << vfuncAdd3 << endl;
    cout << "son2's first virtual Func's address is: " << vfuncAdd4 << endl;
    cout << endl;

    //此处打印了四个对象的第二个虚函数的地址,其中son2的第二个虚函数被override,可见该函数的地址发生了变化.
    cout << "father1's second virtual Func's address is: " << vfuncAdd12 << endl;
    cout << "father1's second virtual Func's address is: " << vfuncAdd22 << endl;
    cout << "son1's second virtual Func's address is: " << vfuncAdd32 << endl;
    cout << "son2's second virtual Func's address is: " << vfuncAdd42 << endl;

    return 0;
}