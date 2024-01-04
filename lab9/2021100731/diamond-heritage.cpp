#include <iostream>

using namespace std;

/*------------------------以下为菱形继承情况------------------------*/
class Vehicle1
{
public:
    Vehicle1(int input):
        speed(input)
        {cout << "Vehicle1 is Created!" << endl;};

    int speed;
    virtual void start(){}
};


class Car1: public Vehicle1
{
public:
    Car1(int input):
        Vehicle1(input)
        {cout << "Car1 is Created!" << endl;};
};


class Boat1: public Vehicle1
{
public:
    Boat1(int input):
        Vehicle1(input)
        {cout << "Boat1 is Created!" << endl;};
};


class AmphibiousVehicle1: public Car1, public Boat1
{
public:
    AmphibiousVehicle1(int input1, int input2):
        Car1(input1),
        Boat1(input2)
        {cout << "AmphibiousVehicle1 is Created!" << endl;};
};


/*------------------------以下用虚继承解决------------------------*/
class Vehicle2
{
public:
    Vehicle2(int input):
        speed(input)
        {cout << "Vehicle2 is Created!" << endl;};

    int speed;
    virtual void start(){}
};


class Car2: virtual public Vehicle2
{
public:
    Car2(int input):
        Vehicle2(input)
        {cout << "Car2 is Created!" << endl;};
};


class Boat2: virtual public Vehicle2
{
public:
    Boat2(int input):
        Vehicle2(input)
        {cout << "Boat2 is Created!" << endl;};
};


class AmphibiousVehicle2: public Car2, public Boat2
{
public:
    AmphibiousVehicle2(int input1, int input2, int input3):
        Vehicle2(input1),
        Car2(input2),
        Boat2(input3)
        {cout << "AmphibiousVehicle2 is Created!" << endl;};
};

int main()
{
    //输出终端可见"Vehicle1 is Created!"文本出现了两次,即创造了两个Vehicle1的不可见对象,产生了菱形继承问题.
    AmphibiousVehicle1 a(1,2);
    cout << endl << endl;
    //输出终端可见"Vehicle1 is Created!"文本仅出现一次,只创造了一个Vehicle1的对象,没有产生菱形继承问题.
    AmphibiousVehicle2 b(1,2,3);

    return 0;
}