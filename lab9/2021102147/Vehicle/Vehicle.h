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

// �����ĸ��๹�������μ̳й�ϵ�������ʹ����̳У�����ֶ�����
// ������ Boat �� Car �඼�̳��� start() ������������ͨ��AmphibiousVehicle�������start()����
// �������޷�ȷ�������ĸ�start()����
// ��̳п���ȷ������̳е���ͬһ����Ψһ�Ļ�����󣬶����Ƕ���������

