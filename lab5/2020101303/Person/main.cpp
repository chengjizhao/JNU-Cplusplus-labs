#include "PERSON.h"
#include <iostream>

using namespace std;
void show(Person &p);

int main() 
{
    Person person_1;
    show(person_1);
    cout << "person_1占用的存储空间: " << sizeof(person_1) << " 字节" << endl << endl;
    
    Person person_2("student_2");
    show(person_2);
    cout << "person_2占用的存储空间: " << sizeof(person_2) << " 字节" << endl << endl;
    
    Person person_3 = Person("student_3","012345678901234567","2000-12-31","Male",170.0,60.0);
    show(person_3);
    cout << "person_3占用的存储空间: " << sizeof(person_3) << " 字节" << endl << endl;
    
    return 0;
}

void show(Person &p)
{
    cout << "Name: " << p.get_name() << endl;
    cout << "ID: " << p.get_person_ID() << endl;
    cout << "Birthday: " << p.get_birthday() << endl;
    cout << "Gender: " << p.get_gender() << endl;
    cout << "Height: " << p.get_height() << " cm" << endl;
    cout << "Weight: " << p.get_weight() << " kg" << endl;
}
//默认构造函数、显示调用构造函数和隐式调用构造函数（当然，构造函数的参数也不同）创建的对象所占用的存储空间一样大。
//这是因为它们都是基于同一个类的定义来创建对象，而这个类的定义在内存中是固定的。