#include <stdio.h>
 int main(){
      int b = 10;
      printf("%s\n", b);
      return 0;
}
/* untitled2—在打印字符串的时候，实际上是打印某个地址开始的所有字符，但是想把整数当字符串打印的时候，这个整数被当成了一个地址，然后printf从这个地址开始去打印字符，直到某个位置上的值为\0。所以，如果这个整数代表的地址不存在或者不可访问，自然也是访问了不该访问的，就会出现内存——segmentation fault。 */