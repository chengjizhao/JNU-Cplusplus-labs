#include<iostream>
#include<vector>
#include<set>

using namespace std;
int myarray[10001];

bool isPrimeNumer(int num)//判断是否素数
{
	for (int i = 2; i * i <= num; ++i)//注意是小于等于
	{
		if (num % i == 0)//例如，数字8
			return false;
	}
	return true;
}

bool isLeafe(int num, int from, int to)//判断是否为叶，看上面的图示理解
{
	for (int i = from; i <= to; ++i)
	{
		if (num == myarray[i])//判断是否被其他数字指向
			return false;
	}
	return true;
}

int calculate(int num)//传入一个数字，返回其各个位置上的数字平方和
{
	int sum = 0;
	while (num != 0)
	{
		sum += (num % 10) * (num % 10);
		num /= 10;
	}
	return sum;
}

int find_roof(int num)//找到num数字对应的根。如果根的结果为1，则证明成功找到幸福数
{
	set<int> myset;
	pair<set<int>::iterator, bool> ret;//用来insert的返回值承接
	while (myarray[num] != num)
	{
		ret = myset.insert(myarray[num]);
		if (ret.second == false)
			return -1;//证明存在循环，不是幸福数字
		num = myarray[num];

	}
	return num;//一个正整数数字的平方可以为其本身，那就是1无疑了
}

int main()
{
	int from, to;
	cin >> from >> to;
	for (int i = 1; i <= 10000; ++i)
	{
		myarray[i] = i;
	}
	for (int i = 1; i <= 10000; ++i)
	{
		myarray[i] = calculate(i);//初始化为i对应值的平方
	}
	int temp = 0;
	for (int i = from; i <= to; ++i)
	{
		if (isLeafe(i, from, to) && find_roof(i) == 1)//的确是叶，同时此叶最终指向根
		{
			temp++;
			cout << i << " ";
			int flag = 1, x = i;
			while (calculate(x) != 1)//计算迭代次数
			{
				x = calculate(x);
				flag++;
			}
			if (isPrimeNumer(i))flag *= 2; //此处对幸福数本身判断是否是素数。
			cout << flag << endl;
		}
	}
	if (temp == 0)
	{
		cout << "SAD" << endl;
	}
	return 0;
}