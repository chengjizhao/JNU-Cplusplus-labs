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
    AmphibiousVehicle(int sp) : Car(sp), Boat(sp) {} // 初始化列表调用虚基类的构造函数  
    void start() override { // 重写 start() 函数，避免歧义  
        Car::start(); // 调用 Car 的 start() 函数  
        Boat::start(); // 调用 Boat 的 start() 函数  
    }
};

//在上面的代码中，我们使用虚继承将 Car 和 Boat 与它们的共同基类 Vehicle 相关联。通过在 AmphibiousVehicle 中使用初始化列表来调用 Car 和 Boat 的构造函数，我们可以确保正确的速度成员变量被初始化。在 AmphibiousVehicle 中重写 start() 函数时，我们通过显式地调用 Car 和 Boat 的 start() 函数来避免歧义。