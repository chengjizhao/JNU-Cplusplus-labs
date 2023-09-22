#include<iostream>
#include<vector>
using namespace std;
int judge(int x)//函数判断数字是否为忧伤数
{
	//拆分数字
	while(x!=1)
	{
		for(int i=0;i<100;i++)
		{
			int a=x%10;//个位数
			int b=x/10%10;//十位数
			int c=x/100%10;//百位数
			int e=a*a+b*b+c*c;
			x=e;
			if(x==1)
			{
				return 1;//忧伤数返回1
			}
		}
		return -1;//不是忧伤数返回-1
	}
	return 1;
}
int main()
{
	vector<int>sad_num;//创建vector容器
	for(int j=0;j<1000;j++)
	{
	if(judge(j)==1)sad_num.push_back(j);//将忧伤数推入vector容器
	}
	cout<<"忧伤的数"<<endl;
	for(int n=0;n<sad_num.size();n++)
	cout<<sad_num[n]<<" ";//输出忧伤数
	return 0;
}