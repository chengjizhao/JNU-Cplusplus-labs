#include <stdio.h>

int main() {

int* p; 
 * p = 1 ;//使用的指针未初始化，解决方法：加一段a=1,*p=a
printf("%d\n", *p); 
return 0;
}