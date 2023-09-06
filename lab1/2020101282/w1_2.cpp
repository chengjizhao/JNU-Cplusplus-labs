#include <stdio.h>
int main() {
  
  int* p;
  printf("%d\n", *p);//调用空指针，本质上因为解引用访问的页面没有分配或者没有权限访问，导致了segmentation fault
  return 0;
  
}
