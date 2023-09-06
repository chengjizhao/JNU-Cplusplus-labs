#include <stdio.h>
#include <string.h>
 
int main(void)
{
    char *ptr = "test";         // 定义一个指向字符串常量"test"的指针 ptr
    
    strcpy(ptr, "TEST");        // 将字符串"TEST"复制到指针 ptr 所指向的内存空间中
    
    return 0;
}
//在这段程序中，首先定义了一个字符指针 ptr，并将其指向字符串常量 "test"。

//接下来，使用 strcpy 函数试图将另一个字符串 "TEST" 复制到指针 ptr 所指向的内存空间中。然而，由于 ptr 指向的是一个字符串常量，它是只读的，不允许进行修改。

//因此，当试图通过 strcpy 函数修改 ptr 所指向的字符串时，会导致段错误（segmentation fault），因为程序试图修改只读内存区域。