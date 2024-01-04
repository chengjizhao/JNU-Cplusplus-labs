#include <iostream>
#include "static.h"

static int staticVar = 0; // 静态变量定义

int GetStaticVar() {
    return staticVar;
}

void static_demo_function() {
    staticVar++; // 静态变量递增
}
