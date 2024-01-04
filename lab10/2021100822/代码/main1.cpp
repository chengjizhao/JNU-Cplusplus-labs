##继承类对象：
##继承类对象是指一个类派生自另一个类的情况。派生类对象包含基类的成员变量，以及自己的成员变量。

class Base {
public:
    int baseData;
};

class Derived : public Base {
public:
    int derivedData;
};

int main() {
    Derived obj;
    obj.baseData = 1;
    obj.derivedData = 2;
    return 0;
}
