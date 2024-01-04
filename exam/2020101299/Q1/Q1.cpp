#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(const string &n, int a) : name(n), age(a) {

    }

    virtual void display() {
        cout << name << ", " << age;
    }
};

class Student : public Person {
private:
    string studentID;
public:
    Student(const string &n, int a, const string &id) : Person(n, a), studentID(id) {

    }

    void display() {
        Person::display();
        cout << ", " << studentID;
    }
};

int main() {
    Person *p1 = new Person("PPP", 10);
    Person *p2 = new Student("SSS", 20, "11223344");
    p1->display();
    cout << endl;
    p2->display();
    cout << endl;
    return 0;
}
