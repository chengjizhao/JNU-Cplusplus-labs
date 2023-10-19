/*文件名：myclass_friend.cpp
程序描述：使用友元或公有函数来实现在外部函数中调用私有成员函数
输入参数：无
输出参数：Private function called.
*/
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
 obj.callPrivateFunction(); //通过公有成员函数间接调用私有成员函数
 friendObj.
 accessPrivateFunction(obj);//通过友元函数调用私有成员函数
 return 0;
}
