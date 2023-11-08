#include<iostream>
using namespace std;
//菱形继承
class Vehicle1
{
 private:
 int speed;
 public:
 Vehicle1(int a=0) : speed(a) {cout << "Vehicle1" <<  endl;}
 virtual int start()
 {return speed;}

};

class Car1 : public Vehicle1
{
 private:
 int x;
 public:
 Car1(int a=0,int b=0) : Vehicle1(a),x(b) {cout << "Car1" << endl;}
 virtual int start()
 {return x;}

};
class Boat1 : public Vehicle1
{
 private:
 int y;
 public:
 Boat1(int a=0,int b=0) : Vehicle1(a),y(b) {cout << "Boat1" << endl;}
 virtual int start() 
 {return y;}

};
class AmphibiousVehicle1 : public Car1,public Boat1
{

 private:
 int z=0;
 public:
 AmphibiousVehicle1(int a,int b,int c,int d) :  Car1(a,b), Boat1(c,d){cout << "AmphibiousVehicle1" << endl;}
 virtual int start() 
 { return z;}
 void show()
 {
    //cout<<Vehicle1::start()<<endl;
    cout<<Car1::start()<<endl;
    cout<<Boat1::start()<<endl;
 }
};



//公共基类
class Vehicle2
{
public:
    Vehicle2(int data1, int data2, int data3) :
    speed1(data1),
    speed2(data2),
    speed3(data3)
    {    cout << "Vehicle2" << endl; }
    virtual ~Vehicle2(){}
    void    start()
    { cout << speed1 <<  endl;}

public:
    int  speed1;
    int  speed2;
    int  speed3;
};

//虚继承方式
class Car2 : virtual public Vehicle2
{
public:
    Car2() :Vehicle2(1, 2, 3), x(1)
    {cout << "Car2" << endl;}
    ~Car2(){}

public:
    int x;
};

//虚继承方式
class Boat2 :  virtual public Vehicle2
{
public:
    Boat2() :Vehicle2(4, 5, 6), y(2)
    {cout << "Boat2" << endl;}
    ~Boat2(){}

public:
    int y;
};

  // 类Car2和类Boat2是虚继承方式
class  AmphibiousVehicle2 : public Car2, public Boat2
{
public:
    //负责对直接基类的初始化以及虚基类的初始化
    AmphibiousVehicle2() : Car2(), Boat2(), Vehicle2(7,8,9), z(3)
    {cout << "AmphibiousVehicle2" << endl; }
    void show()
    {cout << "z=" << z << endl;}

public:
    int z;
};

int main()
{
    AmphibiousVehicle1 amphibiousVehicle1(1,2,3,4);
    amphibiousVehicle1.show();
    AmphibiousVehicle2 data;   
    //直接使用基类数据
    data.speed1 = 10;
    data.start();
    data.show();
    return 0;
}

