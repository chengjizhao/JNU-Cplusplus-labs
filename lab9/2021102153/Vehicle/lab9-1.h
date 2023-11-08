#pragma once
#include<iostream>
using namespace std;
class Vehicle
{
    public:
    int speed;
    virtual void start();
};
class Car :  public Vehicle
{
    public:
    virtual void start();

};
class Boat :  public Vehicle
{
    public:
    virtual void start();

};

class AmphibiousVehicle : public Car ,public Boat
{
    public:
    // AmphibiousVehicle()
    // {
    //     speed=4;
    // }不是虚继承无法确定speed
    virtual void start();
};

class Vehicle1
{
    public:
    int speed;
    virtual void start();
};
class Car1 :  virtual public Vehicle1
{
    public:
    virtual void start();

};
class Boat1 :  virtual public Vehicle1
{
    public:
    virtual void start();

};

class AmphibiousVehicle1 : public Car1 ,public Boat1
{
    public:
    virtual void start();
};
