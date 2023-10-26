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
        privateMethod(); //在共有成员函数中直接调用私有成员函数
    }
};
int main()
{
    Myclass obj;
    obj.publicMethod();
    return 0;
}