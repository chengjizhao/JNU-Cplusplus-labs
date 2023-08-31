#include <stdio.h>

int Add(int a, int b)
{
    return a + b;
}

int Minus(int a, int b)
{
    return a - b;
}

int Multiply(int a, int b)
{
    return a * b;
}

int Divide(int a, int b)
{
    return a / b;
}

int out = 0;

int main()
{
    while(1)
    {
        //创建函数指针数组
        int (*func[4])(int ,int ) = {Add, Minus, Multiply, Divide};
        //创建变量
        int a,b;
        int c;

        printf("请输入待处理数(空格隔开)\n");
        scanf("%d %d",&a,&b);
    
        printf("请输入运算方法(0~3)\n");
        scanf("%d",&c);

        if(0<=c && c<=3)
        {
            printf("结果为:%d\n",func[c](a,b));
        }
        else
        {
            printf("输入错误，请重新输入！\n"); 
        }

        printf("是否继续运算？(继续:1,退出:0)\n"); 
        scanf("%d",&c);
        if(c == 0)
        {
            break;
        }
    }
    printf("程序已退出\n"); 
    return 0;
}


