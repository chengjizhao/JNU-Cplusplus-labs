#ifndef EXTERN_H
#define EXTERN_H

extern int externVar; // extern全局变量声明

namespace myNamespace {
    extern int namespaceVar; // 声明namespace中的extern变量

    void PrintNamespaceVar(); // 声明namespace中的函数
}

#endif // EXTERN_H
