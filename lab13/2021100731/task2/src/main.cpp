#include <iostream>
#include <memory>
#include "header.h"



int main()
{
    shared_ptr<Person> person_1(new Person);
    person_1->name = "LiHua";
    person_1->age  = 20;

    shared_ptr<Person> person_2(new Person);
    person_2->name = "XiaoMing";
    person_2->age  = 18;

    shared_ptr<Address> address_1(new Address);
    address_1->city     = "BeiJing";
    address_1->location = "193";

    shared_ptr<Address> address_2(new Address);
    address_2->city     = "ShangHai";
    address_2->location = "527";

    person_1->address_sharedPtr = address_1;
    person_2->address_sharedPtr = address_2;
    address_1->person_weakPtr = person_1;
    address_2->person_weakPtr = person_2;

    cout << person_1.use_count() << endl;
    cout << person_2.use_count() << endl;
    cout << address_1.use_count() << endl;
    cout << address_2.use_count() << endl;
    //依次输出 1 1 2 2 ,由于address中的person指针是weak类型,故不会增加对应person实体的useCount.这样也就避免了循环引用.
    //接下来通过address来修改对应person的年龄.
    cout << "Age before change: " << person_1->age << endl;

    //使用weak指针之前要先对其进行Lock
    if(auto lockedpersonPtr = address_1->person_weakPtr.lock())
    {
        cout << "Target is Locked!" << endl;
        lockedpersonPtr->age = 40;
    }
    else
    {
        cout << "Target Locked Failed!" << endl;
    }
    
    cout << "Age after change: " << person_1->age << endl << endl;
    //可见析构函数被正确执行,代表循环引用被避免,占用的内存被成功释放.先销毁Address,再销毁对应的Person.
    return 0;
}
