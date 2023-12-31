第九章 - 存储持续性、作用域和链接性:
C++中的变量具有不同的存储持续性，作用域和链接性，这些特性可以分为四类：

自动存储持续性：自动变量在函数定义中声明，包括函数参数。它们在所属函数或代码块开始执行时创建，执行完毕后自动释放内存。C++有两种自动存储持续性的变量：
函数内部局部变量：在函数内部声明的变量，仅在函数作用域内可见。
函数参数：函数参数也具有自动存储持续性，它们在函数调用时创建，函数执行完毕后被销毁。

静态存储持续性：静态变量在函数定义外部声明，或者使用关键字static声明。它们在整个程序的生命周期内存在，不论是否在函数内部。静态变量在第一次声明时初始化，以后保留其值。
函数外部静态变量：在函数外部声明的静态变量，具有文件作用域，仅在声明所在文件可见。
函数内部静态变量：使用关键字static在函数内部声明的静态变量，也具有静态存储持续性，但作用域仅在函数内部。

线程存储持续性（C++11及以后）：用关键字thread_local声明的变量的生命周期与所属的线程一样长。这使得在多线程环境中每个线程都有自己的独立变量副本。

动态存储持续性：使用new运算符分配的内存持续存在，直到使用delete运算符释放它，或者程序结束。这种内存的存储持续性是动态的，有时被称为自由存储或堆。
另外，C++11引入了关键字auto用于自动类型推断，register用于指示寄存器存储（已不常用），以及mutable用于修饰成员变量，允许在const成员函数中修改它们的值。


第十章 - 类和面向对象编程:
在第十章中，介绍了面向对象编程的核心概念，以及如何在C++中定义和使用类。

类的概念：类是一种用户自定义的数据类型，用于描述具有相似属性和行为的对象。类声明描述了数据成员和公共接口，而方法定义描述了成员函数的实现。
公有类访问和私有类访问：C++允许类的成员被分为公有（public）和私有（private）两种访问级别。公有成员可以从类的外部访问，私有成员只能在类的内部访问。
类的数据成员：类可以包含数据成员，这些成员描述了对象的属性。数据成员可以具有不同的数据类型，如整数、浮点数、字符等。
类方法：类可以包含成员函数，也称为类方法，用于描述对象的行为和操作。类方法可以被类的对象调用来执行特定的任务。
构造函数和析构函数：构造函数用于初始化类的对象，在对象创建时自动调用。析构函数用于清理对象在销毁时分配的资源，也在对象销毁时自动调用。

const成员函数：const成员函数用于指示该成员函数不会修改对象的状态。它们可以被用于常量对象，并且不能修改类的非mutable成员变量。
this指针：this指针是一个隐式参数，指向调用成员函数的对象的地址。它允许在成员函数中访问调用对象的成员。
对象数组：可以创建数组来存储类的对象，从而创建多个对象的集合。
类作用域：类的成员具有类作用域，可以使用类名或对象名来访问它们。
抽象数据类型：类提供了一种抽象数据类型（ADT）的实现方式，将数据和相关操作封装在一起，隐藏了内部细节。
