#include "extern.h"
#include<iostream>

int externVar = 42; // extern全局变量定义

namespace myNamespace {
    int namespaceVar = 10; // namespace中的extern变量定义

    void PrintNamespaceVar() {
        std::cout << "Namespace Function: " << namespaceVar << std::endl;
    }
}
