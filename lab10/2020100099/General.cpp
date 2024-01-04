#include <iostream>

class MyClass {
public:
    int data1;
    double data2;
    char data3;

    void printData() {
        std::cout << "Data1: " << data1 << std::endl;
        std::cout << "Data2: " << data2 << std::endl;
        std::cout << "Data3: " << data3 << std::endl;
    }
};

int main() {
    MyClass obj;

    obj.data1 = 10;
    obj.data2 = 3.14;
    obj.data3 = 'A';

    obj.printData();

    return 0;
}
