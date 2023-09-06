#include <stdio.h>

int main() {
    int* ptr = NULL;
    printf("%d\n", *ptr);
    return 0;
}
// ptr是一个空指针，通过*ptr来访问内存会导致段错误。 
