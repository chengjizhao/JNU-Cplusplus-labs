#include <stdio.h>
int main() 
{
    int* ptr = nullptr;
    *ptr = 10; // 定义了一个指针ptr并将其初始化为nullptr，然后试图对空指针进行解引用并赋值。由于ptr指向的内存地址是无效的，所以这个操作会导致段错误。
    return 0;
}