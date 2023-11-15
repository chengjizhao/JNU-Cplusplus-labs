/*
+---------------------+
|       Base          |
+---------------------+
|  - commonData       |
+---------------------+
        |
+---------------------+
|    VirtualBase      |
+---------------------+
|  - commonData       |
|  - virtualData      |
+---------------------+
        |
+---------------------+
|      Derived        |
+---------------------+
|  - commonData       |
|  - virtualData      |
|  - derivedData      |
+---------------------+
*/


#include <iostream>

class Base {
public:
    int commonData;
};

class VirtualBase : virtual public Base {
public:
    int virtualData;
};

class Derived : public VirtualBase {
public:
    int derivedData;
};

int main() {
    Derived derivedObj;

    // 输出内存大小
    std::cout << "Size of Derived object: " << sizeof(derivedObj) << " bytes" << std::endl;

    // 输出对象地址
    std::cout << "Address of Derived object: " << &derivedObj << std::endl;

    return 0;
}
