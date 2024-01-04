/*创建一个汽车类的层次结构，包括一个基类 Car 和至少两个派生类
（例如，Sedan 和 SUV）。在基类中定义虚函数 calculatePrice，
而派生类应该覆盖此函数以计算各自类型的汽车价格。并画UML类图。
*/

#ifndef car_h
#define car_h


class car
{
    public:
    virtual int calculatePrice()=0;
    private:
    int price;
};

class Sedan:public car
{
    public:
    virtual int calculatePrice();
    Sedan();
    private:
    int price; 
};

class SUV:public car
{
    public:
    virtual int calculatePrice();
    SUV();
    private:
    int price;
};

#endif