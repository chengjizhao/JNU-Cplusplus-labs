#include<iostream>
#include<vector>
using namespace std;
//创建数组
int search(int x)
{
    while(x!=1)
    {
        for(int i=0;i<100;i++)
        {
            int a=x%10;
            int b=x/10%10;
            int c=x/100%10;
            int d=x/1000;
            //将数字四位分解
            int e=a*a+b*b+c*c+d*d;//求m
            x=e;
            if(x==1)
            //循环直至结果为1，否则为sad number
            {
                return 1;
            }
        }
        return -1;
    }
    return 1;
}
int main()
{
    vector<int>sad_num;
    vector<int>weal_num;
    for( int i=1;i<1001;i++)
    {
        if(search(i)==1)sad_num.push_back(i);
        if(search(i)==-1)weal_num.push_back(i);
    }
    cout<<"忧伤的数:"<<endl;
    for( int j=0;j<sad_num.size();
    j++)
    cout<<sad_num[j]<<" ";
    cout<<endl<<"幸福的数:"<<endl;
    for( int k=0;k<weal_num.size();
    k++)
    cout<<weal_num[k]<<" ";
    return 0;
}