#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char*argv[])
{
    char*ptr=NULL;
    strncpy(ptr,"abc",5);//访问了不存在的内存地址
    return 0;
}
