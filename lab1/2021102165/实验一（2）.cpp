//数组越界
#include <stdio.h>
int main(){  
    char test[1];  
    printf("%c", test[1000000000]);  
    return 0;
}
//修改：把test[1000000000]改成test[0]或者test[1]