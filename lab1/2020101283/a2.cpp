#include <iostream>
#include <stdlib.h>
#include <cstring>


int main()
{
	int *l1 = nullptr;
	*ptr = 5;//应用了空指针，应避免，解决方法：指针使用前分配内存，应该将nullptr改为new int 
	return 0;
}
  
