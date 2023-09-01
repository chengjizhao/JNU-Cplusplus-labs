#include <stdio.h>
int main()
{
int i=0;
scanf("%d",i);     //将&i打成i，从而出现段错误
printf("%d\n",i);
return 0;
}