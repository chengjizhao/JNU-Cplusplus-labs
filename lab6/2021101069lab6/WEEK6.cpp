#include<iostream>
class MyClass {  
private:  
    void myPrivateFunction() {  
        std::cout << "This is a private function." << std::endl;  
    }  
public:  
    void myPublicFunction() {  
        myPrivateFunction();  
    }  
};  
  
int main() {  
    MyClass obj;  
	//尝试使用外部指针调用私有成员函数
    void (MyClass::*privateFuncPtr)() = &MyClass::myPrivateFunction;  
    (obj.*privateFuncPtr)();  // 发生编译错误：'MyClass::myPrivateFunction' is private  
  
    // 正确写法：调用公有成员函数，然后让它调用私有成员函数  
    obj.myPublicFunction();  // This is a private function.  
    return 0;  
}