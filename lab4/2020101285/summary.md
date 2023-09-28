# external， static， 和namespace 的关系
在C++中，external、static和namespace是用于命名空间和变量声明的关键字。

1. external（外部）关键字：
    - 用于声明外部变量，在C语言中使用较多。
    - 外部变量的存储区域为全局存储区，生命周期与整个程序的运行时间相同。
    - 外部变量具有全局可见性，可以被程序中的其他文件访问和使用。

2. static（静态）关键字：
    - 在函数内部，static修饰的局部变量被称为静态局部变量，保持持久性，即保留上一次的值。
    - 静态局部变量的存储区域为静态存储区，生命周期与整个程序的运行时间相同。
    - 静态局部变量具有局部可见性，只能在定义它们的函数内部访问。
    - 在全局或命名空间作用域中，static修饰的全局变量或函数被称为静态全局变量或静态全局函数。
    - 静态全局变量和静态全局函数的存储区域为静态存储区，生命周期与整个程序的运行时间相同。
    - 静态全局变量和静态全局函数的可见性被限制在当前文件中，不可被其他文件访问。

3. namespace（命名空间）关键字：
    - 用于创建逻辑上的独立区域，用于组织和管理代码中的标识符。
    - 命名空间中的变量可以具有不同的存储区域和生命周期，取决于它们的具体定义。
    - 命名空间的可见性为命名空间内可见，可以通过命名空间限定符（::）访问其中的标识符。


这些关键字和概念在C++中用于组织和管理代码，防止命名冲突，并提供更好的代码可读性和可维护性。

---

# 阅读5-9章总结

1. 第五章：
    - 介绍了循环语句，包括for、while和do-while循环。
    - for循环的语法为：for(初始化； 条件； 更新) {循环体}。
    - while循环的语法为：while(条件) {循环体}。
    - do-while循环先执行循环体，再判断条件是否满足。
    - if语句与while语句类似，都是满足括号内条件则进行语句。
    - if语句后可以接上else语句。
    - If else if else结构可以同时运用多个条件。
    - Switch语句相当于多个if else语句的联合。
    - Break语句和continue语句能使程序跳过部分代码。
    - 使用getline()进行读取文件中的语句。
2. 第六章：
   - 介绍了分支结构和逻辑运算符。
   - if语句与while语句类似，都是满足括号内条件则进行语句。
   - Switch语句可以替代多个if-else语句。
   - 使用getline()读取文件内容。
3. 第七章：
   - 讲述了函数的运用。
   - 需要指定函数类型和输入数据类型。
   - 可以用指针调用数组和结构体。
4. 第九章：
   - 介绍了多文件编译的过程。
   - 用双引号引用头文件。
   - 不能用#include包含其他源代码文件。