#include "person.h"
#include <iostream>

int main() {
  // 使用默认构造函数创建一个对象
  Person p1;

  // 使用带有一个参数的构造函数创建一个对象
  Person p2("Alice");

  // 使用带有多个参数的构造函数创建一个对象
  Person p3("Bob", "1234567890", "2000-01-01", "male", 180.0, 70.0);

  // 打印每个对象占用的存储空间
  std::cout << "Size of p1: " << sizeof(p1) << '\n';
  std::cout << "Size of p2: " << sizeof(p2) << '\n';
  std::cout << "Size of p3: " << sizeof(p3) << '\n';

  return 0;
}

//每个Person对象占用的存储空间取决于编译器和操作系统。
//在上面的示例中，我们使用 sizeof 运算符来获取每个对象占用的存储空间。
//由于 Person 类中只有一个 std::string 类型的成员变量，因此每个对象占用的存储空间应该相同。
//但是，由于编译器和操作系统的不同，每个对象占用的存储空间可能会略有不同。