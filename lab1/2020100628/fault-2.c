#include <stdio.h>
int main()
 {
    int* ptr;
    printf("%d\n", *ptr); // 使用未初始化的指针
    return 0;
}
