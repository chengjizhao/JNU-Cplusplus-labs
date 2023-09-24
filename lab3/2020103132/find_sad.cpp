// 问题： 如果把任意一个正整数 n 拆分成单个数字，比如23，拆成2，3 两个数字，然后全部平方并相加，\
   得到一个新数 m，本例中 m = 2×2 + 3×3=13 如果这个数字m=1， 那么ｎ是忧伤的，否则，继续进行拆分，\
   然后求平方和。本例中就是把13继续拆分为：1×1+3×3=10，1×1+0×0=1，最终23经过三次这样的运算，成了1，\
   因此23 是一个忧伤的数， 任务：用程序实现把1000以内的幸福的数和忧伤的数都找出来。\
   （容器可用set。并且本题中，算到重复的m就可以不用再算了。）
#include<iostream>
#include<cmath>
#include<set>
#include<algorithm>
#include <iterator>
#include<vector>
using namespace std;

set<int>sad;
set<int>happy;
set<int>::iterator it;


bool seek_sad(int n)
{
      set<int>repeat;
      int a,b,c,m;
      a=n/100;//百位
      b=(n%100)/10;//十位
      c=n-a*100-b*10;//个位
      m=pow(a,2)+pow(b,2)+pow(c,2);
      it=repeat.find(m);
      if(it!=repeat.end())
      {
        return false;
      }
      repeat.insert(m);
      n=m;
      if(n==1)
      {
        return true;
      }
    seek_sad(n);
    
}

int main()
{
    for(int i=1;i<1001;i++)
    {
        if(seek_sad(i))
        {
           sad.insert(i);
        }
        else happy.insert(i);
    }
    cout<<"sad number:"<<endl;
    for (it=sad.begin(); it!=sad.end(); ++it)
    {
        cout << ' ' << *it;
    }
    cout<<endl<<"happy number:"<<endl;
    for(it=happy.begin(); it!=happy.end(); ++it)
    {
    
        cout << ' ' << *it;
        
    }
    return 0;
}
