#include<iostream>
#include<memory>
#include<string>
using namespace std;
class Address{
    string city;
    string street;
    weak_ptr<Person> person;
    Address(string city,string street):city(city),street(street){}
    ~Address(){
        cout<<"已析构Address"<<endl;
    }
};
class Person{
    public:
    string name;
    int age;
    shared_ptr<Address> address;
    Person(string name,int age):name(name),age(age){};
    ~Person(){
        cout<<"已析构Person"<<endl;
    }
    void show(){
        cout<<"姓名："<<name<<endl;
        cout<<"年龄："<<age<<endl;
        cout<<"住址："<<address->city<<","<<address->street<<endl;
    }
};

int main(){
    shared_ptr<Address>addr1 =make_shared<Address>("China", "Beijing");
    shared_ptr<Person>person1 =make_shared<Person>("Tom", 15);
    shared_ptr<Person>person2 =make_shared<Person>("Jack", 16);
    person1->address = addr1;
    person2->address = addr1;//表示一个地址可能被多个人共享
    addr1->person = person1;
    person1->show();  
    person2->show();  
    return 0;
}