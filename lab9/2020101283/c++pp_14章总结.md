- 类模板是一种重用代码的方法，可以使用通用术语定义类，并使用模板创建针对特定类型的特殊类。
- 私有继承是一种实现has-a关系的方式，基类的公有成员和保护成员会成为派生类的私有成员，可以在派生类的成员函数中使用它们。
- 保护继承是私有继承的一种变体，基类的公有成员和保护成员会成为派生类的保护成员，派生类的接口可以使用这些成员。
- 使用关键字"virtual"将基类指定为虚基类，从虚基类派生的类只继承一个基类对象，需要满足特定的要求和解决名称二义性。
- 模板类声明可以有三种类型的友元：非模板友元、约束模板友元（根据类被实例化时的类型确定友元类型）、非约束模板友元（所有具体化都是类的友元）。
