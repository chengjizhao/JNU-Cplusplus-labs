#include <stdio.h>
int main(){
   char *p;  
   p = NULL;  
   *p = 'x';  
   printf("%c", *p);  
   return 0;
}
/* untitled1——往受到系统保护的内存地址即内存地址0处写数据——有些内存是内核占用的或者是其他程序正在使用，为了保证系统正常工作，所以会受到系统的保护，而不能任意访问。 */