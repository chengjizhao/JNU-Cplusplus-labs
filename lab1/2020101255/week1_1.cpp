#include <stdio.h>

int main() {
    int arr[3] = {1, 2, 3};
    for (int i = 0; i <= 2; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
// arr是一个包含3个整数的数组。然而，在for循环中，循环变量i超过了数组的边界范围（应为0到2），尝试访问arr[3]会导致段错误。 
