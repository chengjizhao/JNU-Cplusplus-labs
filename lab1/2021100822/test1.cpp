#include "stdio.h"
#include "stdlib.h"

int main(){
    int *p = null;
    *p = 0;///访问了无效地址，产生了段错误
}
