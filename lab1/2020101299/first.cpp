#include<stdio.h>
char *str="hello";//str是全局变量
int main()
{ 
    printf("%s\n",str);//写只读数据会出现segmentation fault
   *str='1';
   return 0;
}