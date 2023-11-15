/*

+---------------------+
|      A              |
+---------------------+
|  - a                |
|  v displayA()       |
+---------------------+
        |
+---------------------+
|      C              |
+---------------------+
|  - a                |
|  v displayA()       |
|  - b                |
|  v displayB()       |
|  - c                |
|  displayC()         |
+---------------------+
        |
+---------------------+
|      B              |
+---------------------+
|  - b                |
|  v displayB()       |
+---------------------+
*/


#include <iostream>

class A {
public:
    int a;
    virtual void displayA() {
        std::cout << "Class A - a: " << a << std::endl;
    }
};

class B {
public:
    char b;
    virtual void displayB() {
        std::cout << "Class B - b: " << b << std::endl;
    }
};

class C : public A, public B {
public:
    double c;
    void displayC() {
        std::cout << "Class C - c: " << c << std::endl;
    }
};

int main() {
    C cObj;
    cObj.a = 10;
    cObj.b = 'X';
    cObj.c = 3.14;

    // 输出内存大小
    std::cout << "Size of Class C object: " << sizeof(cObj) << " bytes" << std::endl;

    // 输出对象地址
    std::cout << "Address of Class C object: " << &cObj << std::endl;

    return 0;
}
