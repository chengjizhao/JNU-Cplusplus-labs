#include "person.h"
#include <iostream>
using namespace std;

int main()
{
    string name, id, bd, gender;
    double h, w;
    cout << "姓名：";
    cin >> name;
    cout << "身份证号：";
    cin >> id;
    cout << "生日：";
    cin >> bd;
    cout << "性别：";
    cin >> gender;
    cout << "身高：";
    cin >> h;
    cout << "体重：";
    cin >> w;

    // 使用默认构造函数创建对象
    Person p1;
    cout << "p1 的大小：" << sizeof(p1) << " 字节" << endl;

    // 使用带参数的构造函数创建对象
    Person p2(name);
    cout << "p2 的大小：" << sizeof(p2) << " 字节" << endl;

    // 使用设置函数设置其他属性
    p2.setID(id);
    p2.setBirthday(bd);
    p2.setGender(gender);
    p2.setHeight(h);
    p2.setWeight(w);

    // 打印其他属性
    cout << "p2 的姓名：" << p2.name << endl;
    cout << "p2 的身份证号：" << p2.getID() << endl;
    cout << "p2 的出生日期：" << p2.getBirthday() << endl;
    cout << "p2 的性别：" << p2.getGender() << endl;
    cout << "p2 的身高：" << p2.getHeight() << endl;
    cout << "p2 的体重：" << p2.getWeight() << endl;

    return 0;
}

// 类的大小在编译时确定，根据类成员变量的类型及数量确定
// name、pid、pbd、pg为string类型，每个占用32个字节
// ph、pw为double类型，每个占用8个字节
// 总共为144个字节
// p1和p2在创建类对象时类成员变量会创建，p1中成员变量没有赋值，但还是会占用空间