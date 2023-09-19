#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int Spow;int Sum;

void Cal(vector<int>&In,vector<int>&Out)//在形参变量前面加入&，引入的是实际变量可以改变，而不是副本
{
for(int i=0;i<10;i++)
  {
    for(int j=0;j<10;j++)
    {
        for(int k=0;k<10;k++)
        {
        Spow=pow(i,2)+pow(j,2)+pow(k,2);//pow()函数需要引入头文件cmath，需要填入变量和需要n次方
        Sum=100*i+10*j+k;
        for(int a:In)
        {
        if(Spow==a)
        Out.push_back(Sum);
        }
        }
    }
  }
}


void Cout(vector<int>In)
{
  int count=0;
  for(int a:In)
  {
    count++;
    cout<<a<<" ";
    if(count%10==0)
    cout<<endl;
  }
  cout<<endl;
}


int main()
{
vector<int> SumVector_1={1,10,100},SumVector_2,SumVector_3,SumVector_4,SumVector_5,SumVector_6,SumVector_7; 
vector<vector<int>>Manager={SumVector_1,SumVector_2,SumVector_3,SumVector_4,SumVector_5,SumVector_6,SumVector_7};
//vector中可以再插入vector类型
for(int i=0;i<Manager.size()-1;i++)
{
  Cal(Manager[i],Manager[i+1]);
  if(Manager[i+1]==Manager[i])
  {
  Cout(Manager[i]);
  }
}
  return 0;
}
//分析下智锐的方法
/*
#include <iostream>
#include <vector>

using std::cin, std::cout, std::endl, std::vector;

bool isSad(int n)
{
	vector<int>already;
	vector<int>::iterator it;                                              
  “引入迭代器实现查找功能”
	while (n != 1)
	{
		int sum = 0;
		while (n > 0)“假设对一个三位数来说，每次取末位平方，然后去掉末位，循环最后剩下小于一的小数，n=0退出循环”
		{
			sum += (n % 10) * (n % 10);“通过取余运算找末位”
			n /= 10; “通过int是整型去掉小数点后的数成功抹掉末位”
		}
		it = std::find(already.begin(), already.end(), sum);
    “查找功能，从迭代器里面找到sum，如果找到则将sum赋给it，如果不能则将.end（）赋给it”
		if (it != already.end())
		{
			return false;“bool类型的函数返回真假”
		}
		n = sum;“将n平方和的结果再赋给n作为下次循环的初值，如果n符合while循环的条件则一直迭代下去”
		already.push_back(sum);“将每次得到的平方和存入到数组中，如此以来每次while循环都能和自己前面得到的所有数据进行比较”
    “从而实现跳出死循环”
	}
	return true;
}

int main()
{
	int count = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (isSad(i))
		{
			++count;
			cout << i;
			if (count % 10 == 0)
				cout << '\n';
			else cout << '\t';
		}

	}
	return 0;
}
*/