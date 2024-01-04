##一般类对象：
##一般类对象是指没有虚函数、没有继承关系的类对象。它们的内存模型是简单的，每个对象包含类的成员变量，不占用额外的内存。

class Simple {
public:
    int data;
};

int main() {
    Simple obj;
    obj.data = 22;
    return 0;
}
