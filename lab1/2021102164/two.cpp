#include <stdio.h>
int main()
{

    char test[1];  
    printf("%c", test[1000000000]);  //出现数组越界，产生段错误
    return 0;
}
