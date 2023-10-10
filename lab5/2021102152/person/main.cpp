#include"Person.h"
#include"Person.cpp"
#include<iostream>
using namespace std;
int main()
{
    string name, id, birthdate, gender;
    double height, weight;
    cout << "name:";
    cin >> name;
    cout << "id:";
    cin >> id;
    cout << "birthdate:";
    cin >> birthdate;
    cout << "gender:";
    cin >> gender;
    cout << "height:";
    cin >> height;
    cout << "weight:";
    cin >> weight;
    cout << endl;
    Person per0 ;//使用默认构造函数创建对象
    Person per1(name) ;//使用单一参数的构造函数创建对象
    per1.set_information( id, birthdate, gender, height, weight) ;//设置其他属性
    Person per2( name, id, birthdate, gender, height, weight) ;//使用多参数的构造函数创建对象
    cout<<"per1"<<endl;
    per1.show() ;
    cout<<"per2"<<endl;
    per2.show() ;
    //打印每个对象占用的存储空间
    cout << "per0 占用存储空间: " << sizeof(per0) << "字节" << endl;
    cout << "per1 占用存储空间: " << sizeof(per1) << "字节" << endl;
    cout << "per2 占用存储空间: " << sizeof(per2) << "字节" << endl;
    return 0;
}
// 类的大小在编译时确定，根据类成员变量的类型及数量确定
// name、id、birthdate、gender为string类型，每个占用32个字节，height、weight为double类型，每个占用8个字节
// 总共占用144个字节