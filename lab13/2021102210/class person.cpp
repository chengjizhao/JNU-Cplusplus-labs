#include<iostream>
#include<memory>
#include<string>
using namespace std ;

class Adress ;

class Person
{
    public:
    Person(string a, int b)
    {
        name=a;
        age=b;
    }
    string name;
    int age;
    void example()
    {
        cout << name << "," << age << endl ;
    }
    shared_ptr<Adress> adress;
    ~Person()
    {
        cout << "delete the person " << name << "," << age << endl ; 
    }
};

class Adress
{
    public:
    Adress(string a,string b)
    {
        streat = a ;
        city = b ;
    }
    string streat;
    string city;
    weak_ptr<Person> person ;
    void example()
    {
        cout << streat << "," << city << endl ;
    }
    ~Adress()
    {
        cout << "delete the adress: " << streat << " in the " << city << endl ;
    }
};

int main()
{
    shared_ptr<Person> bp(new Person("wu",19));
    shared_ptr<Adress> ap(new Adress("a","b"));
    bp->adress=ap ;
    ap->person=bp ;
    bp->adress->example();
    cout << "先销毁person，再销毁adress" << endl ;
    return 0 ;
}