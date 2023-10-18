#include "MyClass.h"
#include "FriendClass.h"

int main()
{
    MyClass myclass;
    FriendClass friend_myclass; 
    //void (MyClass::*Privite_Adress) () = &MyClass::Private_MemberFunc; 
    //不能通过把私有成员函数的指针付给一个外部函数指针的方式调用私有成员函数，会出现“不可访问”的报错
    //正确的写法：
    myclass.Call_Private_MemberFunc(); //通过公有成员函数调用私有成员函数
    friend_myclass.Get_Private_MemberFunc(myclass); //通过友元函数调用私有成员函数
}