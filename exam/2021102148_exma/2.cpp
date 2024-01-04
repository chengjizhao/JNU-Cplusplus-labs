/*
学号2021102148
中级题目（8 mod 3）+1=3
*/

/*
什么是纯虚函数和抽象类?它们如何与虚函数表和虚指针相关联?


纯虚函数：是一个在基类中声明但没有提供实现的虚函数，通过在函数声明后加上 const = 0 来将其声明为纯虚函数。纯虚函数为派生类提供了一个接口，要求派生类必须提供自己的实现。纯虚函数使得基类成为抽象类。
抽象类：包含至少一个纯虚函数的类被称为抽象类。抽象类不能被实例化，只能用作派生其他类的基类。派生类必须实现抽象类中的纯虚函数，否则它们也将成为抽象类。
虚函数表： 对于包含虚函数的类，编译器会在对象的内存中生成一个虚函数表。虚函数表是一个指针数组，其中包含类的虚函数的地址。每个对象都有一个指向其虚函数表的指针。
虚指针： 每个包含虚函数的对象都有一个指向其虚函数表的指针，这个指针称为虚指针。虚指针通常位于对象的内存布局的开头。它使得在运行时能够动态地找到正确的虚函数。
*/
// 考虑以下包含纯虚函数的抽象类的例子：
class Shape
{
public:
    virtual double area() const = 0; // 纯虚函数
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override
    {
        return 3.14 * radius * radius;
    }
};

int main()
{
    // Shape* shape = new Shape(); // 错误，抽象类不能实例化

    Circle circle(5.0);
    Shape *shapePtr = &circle; // 合法，通过基类指针访问派生类对象

    return 0;
}

/*
在这个例子中，Shape 是一个抽象类，因为它包含一个纯虚函数。试图实例化抽象类会导致编译错误。然而，可以通过基类指针访问派生类对象，实现了多态性。在运行时，虚指针指向派生类的虚函数表，确保调用正确的实现。
*/

/*
为什么包含纯虚函数的类不能实例化?请提供解释。


包含纯虚函数的类无法实例化，因为它们定义了接口但未提供完整的实现。纯虚函数要求派生类提供具体实现，使得基类成为抽象类。抽象类本身不包含完整的功能，实例化抽象类对象缺乏定义明确的行为。因此，C++禁止直接实例化抽象类，只能通过派生类创建对象，以确保对象具有完整的实现。这强调了抽象类的角色，作为接口定义和多态性的基础。
*/