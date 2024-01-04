#pragma once
class Vehicle
{
public:
	void start();
};

class Car : virtual public Vehicle
{
};

class Boat : virtual public Vehicle
{
};

class AmphibiousVehicle : public Car, public Boat
{
};

// 以上四个类构成了菱形继承关系，如果不使用虚继承，会出现二义性
// 即由于 Boat 和 Car 类都继承了 start() 方法，因此如果通过AmphibiousVehicle对象调用start()方法
// 编译器无法确定调用哪个start()方法
// 虚继承可以确保子类继承的是同一个、唯一的基类对象，而不是多个基类对象

