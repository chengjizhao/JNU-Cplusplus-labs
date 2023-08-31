#include <stdio.h>
int main(){  
    char test[1];  
    printf("%c", test[999999999]);  //数组越界了，把数组改回正常即可
    return 0;
}