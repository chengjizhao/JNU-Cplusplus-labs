#include "MyClass.h"
#include <iostream>
using namespace std;

void MyClass::Private_MemberFunc()
{
    cout << "Private!!!" << endl; 
}

void MyClass::Call_Private_MemberFunc()
{
    Private_MemberFunc();
}

