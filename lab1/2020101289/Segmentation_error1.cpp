#include <stdio.h>
int main(){
    int largeArray[10000000]; //allocating memory in stack
    printf("OK\n");
    return 0;
}
/*原因是堆栈区域是有限的。 这意味着这个大数组所需的内存不可用。
最终，您的程序正试图超出该段。
如果我们需要更多内存（大于堆栈上的可用内存），我们可以使用堆。 
但是，堆也有限制； 因此，如果我们不断增加内存大小，就会出现错误。
*/