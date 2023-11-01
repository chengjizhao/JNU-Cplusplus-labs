#include <iostream>

class One {
public:
    virtual void run() {
        std::cout << "One::run()正在运行..." << std::endl;
    }
};

class Two : public One {
public:
    void run() override {
        std::cout << "Two::run()正在运行..." << std::endl;
    }
};

int main() {
    One One_Obj;
    Two Two_Obj;

    One* One_ptr = &Two_Obj;

    One_Obj.run(); // 调用 One_Obj.run()
    Two_Obj.run(); // 调用 Two_Obj.run()
    One_ptr->run(); // 调用 One_ptr->run()，虚函数表的作用
    std::cout << &(One::run) << std::endl;
    std::cout << &(Two::run) << std::endl;
    //std::cout << One_ptr->run << std::endl;
    return 0;
}
