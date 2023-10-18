#include <iostream>  
  
class MyClass {  
public:  
    static void callPrivateFunction(MyClass* obj) {  
        obj->privateFunction();  
    }  
  
private:  
    void privateFunction() {  
        std::cout << "This is a private function." << std::endl;  
    }  
};  
  
int main() {  
    MyClass obj;  
    MyClass::callPrivateFunction(&obj);  
  
    return 0;  
}
//在C++中，私有成员函数只能在类的内部使用，无法直接从外部调用。这是C++为了保证对象封装性的重要规则。不过，可以通过一种技巧来间接调用私有成员函数，通过类的公共静态成员函数来调用私有成员函数。在这个例子中，创建了一个公共静态成员函数callPrivateFunction，它接受一个指向MyClass对象的指针作为参数，并调用该对象的私有成员函数privateFunction。虽然私有成员函数仍然不能从类的外部直接调用，但通过这种方式，可以间接地调用私有成员函数。同时，这种做法也遵循了封装性的原则，因为没有破坏对象的封装性，而是通过类的公共静态成员函数来访问私有成员函数。
