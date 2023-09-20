#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool is_sad(int n)
{
    vector<int> past_sum;//存放每一次的计算结果
    vector<int>::iterator it;//迭代器：检测结果是否重复
    while(n!=1)//当最后结果为1时是忧伤的数字
    {
        int sum=0;
        while(n>0)
        {
            sum+=(n%10)*(n%10);//实现各位数的平方和相加
            n/=10;
        }
        it = find(past_sum.begin(), past_sum.end(), sum);
        if (it!= past_sum.end())//幸福的数字
		{
			return false;
		}
        n=sum;//继续拆分运算
        past_sum.push_back(sum);//存起每次的计算结果
     }  
     return true;
}

int main()
{
    
    int n=1000,i,count=0;
    vector<int>  happy(0);
    vector<int>  sad(0);
    for(i=1;i<=n;i++)//存起幸福的数字和忧伤的数字
	{
	
       if(is_sad(i))
       {
       	   sad.push_back(i);
		}
        else
        {
            happy.push_back(i);
        }
	  }
    cout<<"1000内悲伤的数字有："<<endl;
    for(int i = 0; i < sad.size(); i++)
    {
        cout << sad[i] << " ";
        count++;
        if(count%10==0)
        {
            cout<<endl;
        }
    }
    cout<<"1000内幸福的数字有："<<endl;
    count=0;
    for(int i = 0; i < happy.size(); i++)
    {
        cout << happy[i] << " ";
        count++;
        if(count%10==0)
        {
            cout<<endl;
        }
    }
    return 0;
}