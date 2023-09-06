#include <stdlib.h>

int main() 
{
  
  int* ptr = (int*)malloc(sizeof(int));
  free(ptr);
  *ptr = 10;//引用了已经释放的内存
  return 0;
  
}
