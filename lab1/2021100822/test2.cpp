#include "stdio.h"
#include "stdlib.h"
int main(){
    int p=malloc(256);
    p[256]=0;///数组越界，访问了未知的内存
    return 0；
}
