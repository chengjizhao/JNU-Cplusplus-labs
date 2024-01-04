class Class {
public:
    virtual void Method() {

        Operation1();
        Operation2();
    }

    virtual void Operation1() = 0;
    virtual void Operation2() = 0;
};

class ConcreteClass : public Class {
public:
    void Operation1() override {
    }

    void Operation2() override {
    }

    void ConcreteOperation() {
    }
};

int main() {
    Class* obj = new ConcreteClass();
    obj->Method();  
    delete obj;

    return 0;
}
