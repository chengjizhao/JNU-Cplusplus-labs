##虚基类的类对象：
##虚基类用于解决多继承的菱形问题。虚基类对象包含一个指向虚基类子对象的偏移量。

class Base {
public:
    int data;
};

class VirtualBase : virtual public Base {
public:
    int virtualData;
};

class Derived : public VirtualBase {
public:
    int derivedData;
};

int main() {
    Derived obj;
    obj.data = 1;
    obj.virtualData = 2;
    obj.derivedData = 3;
    return 0;
}
