#include <stdio.h>	
int main(int argc, char *argv[])
{
  int *ptr = (int *)0;
 *ptr = 100;//访问了系统保护的地址 
 return 0;
}
