##基类有虚函数且子类有自己的更多的虚函数的类对象：
##派生类包含指向自己的虚函数表和指向基类的虚函数表的指针。

class Base {
public:
    virtual void func1() {}
    int data;
};

class Derived : 公共 Base {
public:
    virtual void func2() {}
    int derivedData;
};

int main() {
    Derived obj;
    obj.data = 1;
    obj.derivedData = 2;
    return 0;
}
