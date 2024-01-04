#include <iostream>
class Myclass
{
    private:
    void privateMethod()
    {
        std::cout << "This is a private method." << std::endl;
    }
    public:
    void publicMethod()
    {
        std::cout << "This is a public method." << std::endl;
    }
};
int main()
{
    Myclass obj;
    void (MyClass::*privateFuncPtr)()=&MyClass::privateMethod;
    (obj.*privateFuncptr)();
    obj.publicMethod();
    return 0;
}