class Vehicle {
public:
    Vehicle(int sp) : speed(sp) {}
    virtual void start() {
        std::cout << "Vehicle started." << std::endl;
    }
    int speed;
};

class Car : virtual public Vehicle {
public:
    Car(int sp) : Vehicle(sp) {}
};

class Boat : virtual public Vehicle {
public:
    Boat(int sp) : Vehicle(sp) {}
};

class Vehicle {
public:
    Vehicle(int sp) : speed(sp) {}
    virtual void start() {
        std::cout << "Vehicle started." << std::endl;
    }
    int speed;
};

class Car : virtual public Vehicle {
public:
    Car(int sp) : Vehicle(sp) {}
};

class Boat : virtual public Vehicle {
public:
    Boat(int sp) : Vehicle(sp) {}
};

class AmphibiousVehicle : public Car, public Boat {
public:
    AmphibiousVehicle(int sp) : Car(sp), Boat(sp) {} // ��ʼ���б���������Ĺ��캯��  
    void start() override { // ��д start() ��������������  
        Car::start(); // ���� Car �� start() ����  
        Boat::start(); // ���� Boat �� start() ����  
    }
};

//������Ĵ����У�����ʹ����̳н� Car �� Boat �����ǵĹ�ͬ���� Vehicle �������ͨ���� AmphibiousVehicle ��ʹ�ó�ʼ���б������� Car �� Boat �Ĺ��캯�������ǿ���ȷ����ȷ���ٶȳ�Ա��������ʼ������ AmphibiousVehicle ����д start() ����ʱ������ͨ����ʽ�ص��� Car �� Boat �� start() �������������塣