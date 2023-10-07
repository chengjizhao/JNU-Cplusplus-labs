#include "person.h"

int main() {
    // 使用默认构造函数创建一个person对象
    Person person1;

    // 使用带参数的构造函数创建一个person对象
    Person person2("Alice", "1234567890", "1990-01-01", "Female", 165.0, 60.0);

    // 查询和设置属性
    person1.setName("Bob");
    person1.setID("0987654321");
    person1.setDOB("1995-05-05");
    person1.setGender("Male");
    person1.setHeight(180.0);
    person1.setWeight(75.0);

    // 输出属性信息
    person1.printInfo();
    std::cout << std::endl;
    person2.printInfo();

    return 0;
}
