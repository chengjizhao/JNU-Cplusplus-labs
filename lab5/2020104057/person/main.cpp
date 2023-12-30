#include "person.h"
#include <iostream>

using namespace std;

int main() 
{
  //设置名字，身份证号， 出生年月日，性别，身高，体重
  Person p1;
  Person p2("Lisa");
  Person p3("Jane", "4536251");
  Person p4("Claire", "1234567", "2000-11-18", 'W', 160, 50);

  // 打印每个对象占用的存储空间
  cout << "Size of p1: " << sizeof(p1) << " bytes" << endl;
  cout << "Size of p2: " << sizeof(p2) << " bytes" << endl;
  cout << "Size of p3: " << sizeof(p3) << " bytes" << endl;
  cout << "Size of p4: " << sizeof(p4) << " bytes" << endl;

  //  解释为什么对象的尺寸是这么大？
  cout << "对象的尺寸基于它的数据成员。std::string对象的大小取决于其实现，但通常它包一个指向字符数组的指针、一个大小和一个容量。"<<endl;
  cout << "通常，double数据类型通常为8字节，char为1字节。但实际上，由于编译器可能会为了对齐而在对象中插入填充字节，Person对象大小可能大于这些成员的累加"<<endl;

  system("pause");
  return 0;
}
