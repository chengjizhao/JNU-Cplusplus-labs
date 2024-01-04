class Abstract {
public:
    virtual void pureVirtualFunction() = 0;  // 纯虚函数
};

int main() {
    // 代码无法编译，因为 Abstract 是抽象类
    // Abstract obj;  // 错误：无法创建抽象类的实例

    return 0;
}