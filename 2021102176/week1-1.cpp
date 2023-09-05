//在C++代码中使用指针操作，访问未分配的内存空间，可以引发分段错误。

#include<iostream>
using namespace std;

int main(){
    int* ptr = nullptr; // 声明一个空指针
    *ptr = 10; // 对空指针解引用，访问未分配的内存
    return 0;
}
