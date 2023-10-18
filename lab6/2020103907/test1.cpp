#include <iostream>

using namespace std;
class MyClass {
private:
    void privateFunction() {
        cout << "Private function called." << endl;
    }
    friend class FriendClass;//声明FriendClass为友元类
public:
    void callPrivateFunction() {
        privateFunction(); //类的内部函数
    }
};

class FriendClass {
public:
    void accessPrivateFunction(MyClass& obj) {
        obj.privateFunction();
    }
};


int main() {
    MyClass obj;
    FriendClass friendObj;
    
     // 通过函数指针调用私有成员函数（这是错误的）
    
    //正确调用方法
    obj.callPrivateFunction(); //通过公有成员函数间接调用私有成员函数
    friendObj.accessPrivateFunction(obj);//通过友元函数调用私有成员函数

    return 0;
}
