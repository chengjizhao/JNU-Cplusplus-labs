// 问题： 如果把任意一个正整数 n 拆分成单个数字，比如23，拆成2，3 两个数字，然后全部平方并相加，\
   得到一个新数 m，本例中 m = 2×2 + 3×3=13 如果这个数字m=1， 那么ｎ是忧伤的，否则，继续进行拆分，\
   然后求平方和。本例中就是把13继续拆分为：1×1+3×3=10，1×1+0×0=1，最终23经过三次这样的运算，成了1，\
   因此23 是一个忧伤的数， 任务：用程序实现把1000以内的幸福的数和忧伤的数都找出来。
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include <iterator>
using namespace std;
vector<int>sad;
vector<int>happy;
int seek(int s)
{
    int n,a,b,c,m,i;
    n=s;
    for(i=1;i<1001;++i)
    {
        a=n/100;//百位
        b=(n%100)/10;//十位
        c=n-a*100-b*10;//个位
        m=pow(a,2)+pow(b,2)+pow(c,2);
        if(m==1)
        {
            sad.push_back(s);
            return 0;
        }
        else happy.push_back(s);
        n=m; 
    }
    return 0;
}

int main()
{
    int z;
    for(int i=1;i<1001;++i)
    {
        seek(i);
    }
    cout<<"sad number:"<<endl;
    for(z=0;z<sad.size();++z)
    {
        cout<<sad[z]<<" ";
    }
    /*cout<<endl<<"happy number:"<<endl;
    for(int w=0;w<1001;++w)
    {
         cout<<happy[w]<<" ";
    }*/
    return 0;
}

