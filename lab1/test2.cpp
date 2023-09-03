
#include <stdio.h> 
#include <stdlib.h>


int main(){ 
  int* p = (int*)0xC00000ffff; //访问了不属于进程地址空间的内存,解决方法：访问属于地址空间的内存
   *p = 1; 
}