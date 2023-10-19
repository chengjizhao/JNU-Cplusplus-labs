/*文件名：myclass_Lambda.cpp
程序描述：利用Lamda表达式使得可以在Lambda中访问私有成员函数
输入参数：无
输出参数：Private function called.
*/


#include <iostream>

class MyClass {
private:
    void privateFunction() {
        std::cout << "Private function called." << std::endl;
    }

public:
    void callPrivateFunction() {
        auto lambda = [this](){
            privateFunction(); // 可以在Lambda中访问私有成员函数
        };
        lambda();
    }
};

int main() {
    MyClass obj;
    obj.callPrivateFunction();

    return 0;
}
