#include <iostream>

//一般类对象
class GeneralClass {
public:
 int generalVar;
};

// 继承类对象
class InheritedClass : public GeneralClass {
public:
 int inheritedVar;
};

// 带虚函数的类对象
class VirtualClass {
public:
 virtual void virtualFunc() {
 std::cout << "Virtual function called." << std::endl;
 }
};

// 基类有虚函数的子类对象
class DerivedClass : public VirtualClass {
public:
 void derivedFunc() {
 std::cout << "Derived function called." << std::endl;
 }
};

// 基类有虚函数且子类有自己的更多的虚函数的类对象
class MoreDerivedClass : public DerivedClass {
public:
 void moreDerivedFunc() {
 std::cout << "More derived function called." << std::endl;
 }
};

// 多继承的类对象
class MultipleInheritanceClass : public GeneralClass, public VirtualClass {
public:
 int multipleVar;
};

// 虚基类的类对象
class VirtualBaseClass {
public:
 int virtualBaseVar;
};

class VirtualDerivedClass : virtual public VirtualBaseClass {
public:
 int virtualDerivedVar;
};

int main() {
 GeneralClass generalObj;
 InheritedClass inheritedObj;
 VirtualClass virtualObj;
 DerivedClass derivedObj;
 MoreDerivedClass moreDerivedObj;
 MultipleInheritanceClass multipleObj;
 VirtualDerivedClass virtualDerivedObj;

 std::cout << "Size of GeneralClass object: " << sizeof(generalObj) << std::endl;
 std::cout << "Size of InheritedClass object: " << sizeof(inheritedObj) << std::endl;
 std::cout << "Size of VirtualClass object: " << sizeof(virtualObj) << std::endl;
 std::cout << "Size of DerivedClass object: " << sizeof(derivedObj) << std::endl;
 std::cout << "Size of MoreDerivedClass object: " << sizeof(moreDerivedObj) << std::endl;
 std::cout << "Size of MultipleInheritanceClass object: " << sizeof(multipleObj) << std::endl;
 std::cout << "Size of VirtualDerivedClass object: " << sizeof(virtualDerivedObj) << std::endl;

 return 0;
}
