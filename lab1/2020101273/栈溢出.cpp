%栈溢出
#include<stdio.h>
#include<stdlib.h>
void main()
{
    main();
}
%数组太大导致栈不够
%解决方法：用malloc分配到heap上：
%double* eigvl = (double*) malloc(sizeof(double)*N);