#include <iostream>
#include <string>
#include <ctime>

class Person {
public:
    // 构造函数1：默认构造函数
    Person() : name(""), idCard(""), birthDate(""), gender(' '), height(0.0), weight(0.0) {}

    // 构造函数2：带参数的构造函数
    Person(const std::string& name, const std::string& idCard, const std::string& birthDate, char gender, double height, double weight)
        : name(name), idCard(idCard), birthDate(birthDate), gender(gender), height(height), weight(weight) {}

    // 查询和设置函数
    const std::string& GetName() const { return name; }
    void SetName(const std::string& newName) { name = newName; }

    const std::string& GetIdCard() const { return idCard; }
    void SetIdCard(const std::string& newIdCard) { idCard = newIdCard; }

    const std::string& GetBirthDate() const { return birthDate; }
    void SetBirthDate(const std::string& newBirthDate) { birthDate = newBirthDate; }

    char GetGender() const { return gender; }
    void SetGender(char newGender) { gender = newGender; }

    double GetHeight() const { return height; }
    void SetHeight(double newHeight) { height = newHeight; }

    double GetWeight() const { return weight; }
    void SetWeight(double newWeight) { weight = newWeight; }

private:
    std::string name;
    std::string idCard;
    std::string birthDate;
    char gender;
    double height;
    double weight;
};

int main() {
    // 创建一个Person对象并打印其大小
    Person person1;
    std::cout << "Size of person1: " << sizeof(person1) << " bytes" << std::endl;

    // 创建一个Person对象并打印其大小
    Person person2("Alice", "1234567890", "2000-01-01", 'F', 160.0, 55.0);
    std::cout << "Size of person2: " << sizeof(person2) << " bytes" << std::endl;

    // 创建一个Person对象并打印其大小
    Person person3("Bob", "0987654321", "1995-03-15", 'M', 175.0, 75.0);
    std::cout << "Size of person3: " << sizeof(person3) << " bytes" << std::endl;

    return 0;
}
//此代码定义了一个名为Person的类，它具有名字、身份证号、出生年月日、性别、身高和体重等属性，其中只有名字是公共属性（public），其他属性都是私有的（private）。类中有查询和设置这些属性的函数。
//在主程序中，我们首先创建了一个默认构造函数创建的person1对象，并打印其大小。然后，我们使用带参数的构造函数创建了person2和person3对象，并分别打印它们的大小。
//对象的大小取决于其成员变量的大小和内存对齐。在这个示例中，Person类包含6个成员变量，包括3个字符串（name、idCard、birthDate）、1个字符（gender）以及2个双精度浮点数（height、weight）。字符串的大小取决于字符串内容的长度，字符通常占用1字节，双精度浮点数通常占用8字节。此外，由于内存对齐的原因，每个成员变量可能会被填充到特定的字节边界，以确保访问变量时的效率。
//因此，对象的大小是所有成员变量大小的总和，加上可能的填充字节。每个平台和编译器都可能有不同的对齐规则，所以对象的大小可能会有所不同。您可以使用sizeof运算符来获取对象的大小。在上述代码中，我们使用sizeof运算符来打印每个Person对象的大小。
