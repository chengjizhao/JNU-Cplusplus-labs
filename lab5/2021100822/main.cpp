#include <iostream>
#include "extern.h"
#include "static.h" 

int main() {
    // 使用extern全局变量
    std::cout << "Extern Variable in main.cpp: " << externVar << std::endl;

    // 使用namespace的变量
    std::cout << "Namespace Variable in main.cpp: " << myNamespace::namespaceVar << std::endl;

    // 调用namespace中的函数
    myNamespace::PrintNamespaceVar();

    // 使用static变量，它将在函数退出后保持其值
    //static_demo_function();
    std::cout << "Static Variable in main.cpp: " << GetStaticVar() << std::endl;

    // 输出extern、static、namespace变量的地址
    std::cout << "Address of externVar: " << &externVar << std::endl;
    //std::cout << "Address of staticVar: " << &staticVar << std::endl;
    std::cout << "Address of namespaceVar: " << &myNamespace::namespaceVar << std::endl;

    return 0;
}
