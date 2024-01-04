##基类有虚函数的子类对象：
##派生类对象继承了基类的虚函数表指针，并添加自己的成员变量。

class Base {
public:
    virtual void func() {}
    int data;
};

class Derived : public Base {
public:
    int derivedData;
};

int main() {
    Derived obj;
    obj.data = 1;
    obj.derivedData = 2;
    return 0;
}
