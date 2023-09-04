#include <stdio.h>
int main(){  
    char test[1];  
    printf("%c", test[1000000000]); //内存越界，地址不存在，出现段错误 
    return 0;
}