##带虚函数的类对象：
##带有虚函数的类对象包含一个指向虚函数表（vtable）的指针，用于实现动态绑定（多态性）。

class Base {
public:
    virtual void func() {}
    int data;
};

int main() {
    Base obj;
    obj.data = 1;
    return 0;
}
