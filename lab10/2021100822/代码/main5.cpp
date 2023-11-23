##多继承的类对象：
##多继承的类对象包含多个基类的成员变量，并且可能有虚函数表指针。

class Base1 {
公共:
    int data1;
};

class Base2 {
公共:
    int data2;
};

class Derived : 公共 Base1, 公共 Base2 {
公共:
    int derivedData;
};

int main() {
    Derived obj;
    obj.data1 = 1;
    obj.data2 = 2;
    obj.derivedData = 3;
    return 0;
}
