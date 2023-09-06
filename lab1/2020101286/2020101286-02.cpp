#include <stdio.h>
int main() 
{
    char*str = "Segmentation Fault";
    str[0] = 's'; // 定义了一个指向字符串常量的字符指针str，在这里试图修改字符串的第一个字符由大写变小写s，由于字符串常量是只读的，所以这个操作会导致段错误。
    return 0;
}