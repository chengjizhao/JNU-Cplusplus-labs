#include "header.h"
#include <iostream>


using namespace std;

/***************************************************
*函数名称：bubble
*输入变量：double* ar
*返回数值：NULL
*功能简介：冒泡排序
***************************************************/
void bubble(double* ar)
{
    int i,k;
    double w;
    for(i=0;i<3;i++)
    {
        for(k=0;k<3-i;k++)
        {
            if(ar[k]>ar[k+1])
            {
                w=ar[k];
                ar[k]=ar[k+1];
                ar[k+1]=w;
            }
        }
    }
}

/***************************************************
*函数名称：Calculate
*输入变量：Sales *s
*返回数值：NULL
*功能简介：数据处理计算
***************************************************/
void SALES::Calculate(Sales *s)
{
    double sum = 0;
    for(int i=0; i<4; i++)
    {
        sum = sum + s->sales[i];
    }
    bubble(s->sales);
    s->max = s->sales[3];
    s->min = s->sales[0];
    s->average = sum / 4;
}

/***************************************************
*函数名称：setSales
*输入变量：Sales *s, const double ar[], int n
*返回数值：NULL
*功能简介：
***************************************************/
void SALES::setSales(Sales *s, const double ar[], int n)
{
    for(int i=0; i<4; i++)
    {
        s->sales[i] = ar[i];
    }
    Calculate(s);
}

/***************************************************
*函数名称：setSales
*输入变量：Sales *s
*返回数值：NULL
*功能简介：
***************************************************/
void SALES::setSales(Sales *s)
{
    cin >> s->sales[0] >> s->sales[1] >> s->sales[2] >> s->sales[3];
    Calculate(s);
}

/***************************************************
*函数名称：showSales
*输入变量：Sales *s
*返回数值：NULL
*功能简介：显示业绩数据
***************************************************/
void SALES::showSales(Sales *s)
{
    cout << "总业绩" << endl;
    cout << s->sales[0] << " " << s->sales[1] << " " << s->sales[2] << " " << s->sales[3] << endl;
    cout << "平均 最大 最小" << endl;
    cout << s->average << " " << s->max << " " << s->min << endl;
}
