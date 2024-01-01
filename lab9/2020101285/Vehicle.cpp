#include<iostream>
using namespace std;
class Vehicle{
public:
    int speed;
    Vehicle(int value):speed(value) { }
    virtual void start(){
        cout<<"vehicle start speed "<<speed<<endl;
    }
};
class Car : public Vehicle{
public:
    Car(int value):Vehicle(2*value){ }
    virtual void start(){
        cout<<"Car start speed "<<speed<<endl;
    }
};
class Boat : public Vehicle{
public:
    Boat(int value):Vehicle(value/2){ }
    virtual void start(){
        cout<<"Boat start speed "<<speed<<endl;
    }
};
class AmphibiousVehicle : public Car, public Boat{
public:
    AmphibiousVehicle(int value) : Car(value), Boat(value){}
    virtual void start(){
        //cout<<"AmphibiousVehicle start speed"<<speed<<endl;
        //菱形继承存着两份数据，直接使用回报错："AmphibiousVehicle::speed" 不明确
        //可使用虚继承只保留一份数据，需要注意两点：
        //1. 添加public virtual
        //2. 初始化Grandparent
        cout<<"AmphibiousVehicle start speed "<<(Car::speed + Boat::speed)/2<<endl;
    }
};

int main(){
    Vehicle Vehicle1(20);
    Car Vehicle2(20);
    Boat Vehicle3(20);
    AmphibiousVehicle Vehicle4(20);
    Vehicle* pV1 = &Vehicle1;
    Vehicle* pV2 = &Vehicle2;
    Vehicle* pV3 = &Vehicle3;
    Car* pV4 = &Vehicle4;
    pV1 ->start();
    pV2 ->start();
    pV3 ->start();
    pV4 ->start();
    return 0;
}