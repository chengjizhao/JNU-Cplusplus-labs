#include <stdio.h>

int *func()
{
    int n = 1;
    return &n;   
}

int main()
{
    int *p = func() ;
    int n = *p; //ָ����ָ��������ѱ�ϵͳ���գ������������int nǰ�����static
    printf("%d",n);
    return 0;
}

