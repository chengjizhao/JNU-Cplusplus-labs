#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    virtual void display() {
        cout << "Display function in Person" << endl;
    }
};

int main() {
    Person p;
    long* vptr = *(long**)&p; // 获取对象p的虚函数表地址
    long* vfunc = (long*)*vptr; // 获取第一个虚函数的地址
    ((void (*)())vfunc)(); // 调用第一个虚函数
    return 0;
}