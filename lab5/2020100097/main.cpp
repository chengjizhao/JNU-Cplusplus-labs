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

    Person p1;
    cout << "p1 的大小：" << sizeof(p1) << " 字节" << endl;


    Person p2(name);
    cout << "p2 的大小：" << sizeof(p2) << " 字节" << endl;


    p2.setID(id);
    p2.setBirthday(bd);
    p2.setGender(gender);
    p2.setHeight(h);
    p2.setWeight(w);

    cout << "p2 的姓名：" << p2.name << endl;
    cout << "p2 的身份证号：" << p2.getID() << endl;
    cout << "p2 的出生日期：" << p2.getBirthday() << endl;
    cout << "p2 的性别：" << p2.getGender() << endl;
    cout << "p2 的身高：" << p2.getHeight() << endl;
    cout << "p2 的体重：" << p2.getWeight() << endl;

    return 0;
}