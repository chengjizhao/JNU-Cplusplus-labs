#include<stdio.h>

int main()
{
    int i=1,j=1;
    scanf("%d",i,j);//出现段错误,应该为&i,&j
    printf("%d",i,j);
    return 0;
}