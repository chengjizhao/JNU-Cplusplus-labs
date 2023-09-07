#include<stdio.h>
int main()
{
    main();//函数不断调用自身，导致return函数遥不可及，挤爆了内存，处理该死循环就可以解决问题
    return 0;
}
