#include "lab9-1.h"
void Vehicle::start()
{   this->speed=1;
    cout << "Vehicle" << endl;
}
void Car::start()
{   this->speed=2;
    cout << "Car" << endl;
}

void Boat::start()
{   this->speed=3;
    cout << "Boat" << endl;
}

void Vehicle1::start()
{
    this->speed=1;
    cout << "Vehicle1" << endl;
}
void Car1::start()
{
    this->speed=2;
    cout << "Car1" << endl;
}

void Boat1::start()
{
    this->speed=3;
    cout << "Boa1" << endl;
}
void AmphibiousVehicle1::start()
{
    this->speed=4;//使用虚继承可以直接定义该数据
    cout << "AmphibiousVehicle1" << endl;
}
void AmphibiousVehicle::start()
{
    // this->speed=4;未使用虚继承，有来自Vehicle类的两份数据，造成数据的冗余和二义性
    cout << "AmphibiousVehicle" << endl;
}

int main()
{
    
    AmphibiousVehicle a;//未使用虚继承时，虚函数重写后可以直接调用a.start();虚函数在此类中未重写则无法确定函数
    a.start();
    a.Car::start();
    a.Boat::start();
    cout << a.Car::speed << endl;//可使用类名调用数据和函数
    // cout << a.speed << endl;不使用虚继承有两份数据，无法明确
    //虚函数重写不会造成数据冗余

    AmphibiousVehicle1 b;//使用虚继承时，虚函数重写后可以直接调用b.start();
    b.Car1::start();
    b.Boat1::start();
    b.start();
    cout << b.speed << endl;//使用虚继承有一份数据可直接用

}
//虚继承通过虚基类指针和虚基类表实现，每个虚继承的子类都有一个虚基类指针（占用一个指针的存储空间，4字节）和虚基类表（也被称作虚基表，不占用类对象的存储空间）（需要强调的是，虚基类依旧会在子类里面存在拷贝，只是仅仅最多存在一份而已，并不是不在子类里面了）；当虚继承的子类被当做父类继承时，虚基类指针也会被继承。
//实际上，vbptr 指的是虚基类表指针（virtual base table pointer，也叫虚基表指针），该指针指向了一个虚基类表（virtual table），虚表中记录了虚基类与本类的偏移地址；通过偏移地址，这样就找到了虚基类成员，而虚继承也不用像普通多继承那样维持着公共基类（虚基类）的两份同样的拷贝，节省了存储空间。

