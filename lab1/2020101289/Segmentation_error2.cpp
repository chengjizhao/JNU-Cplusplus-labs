#include <stdio.h>
void check(){
    check();
}
int main(){
    check();
}
/*不添加基本情况的情况下创建递归函数也会导致堆栈溢出
在上面的代码中，检查函数将不断调用自身并在堆栈上创建它的副本，
一旦程序的可用内存被消耗，这将导致段错误。
*/