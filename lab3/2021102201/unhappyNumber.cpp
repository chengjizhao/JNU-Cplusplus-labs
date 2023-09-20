#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

const int N = 1000;

using namespace std;

//消除重复的数
vector<int> EraseRepeat(vector<int> vec)
{
	vector<int>::iterator i = unique(vec.begin(), vec.end());
	vec.erase(i, vec.end());
	return vec;
}

int main()
{
	int searched = 0; //表示这个数是否被搜索过
	int markedOver = 0; //表示marked容器中的数是否移动到其他容器中
	vector<int> unhappy; //忧郁数容器，下同理
	vector<int> happy;
	vector<int> marked;
	for (int i = 1; i <= 1000; i++)
	{
		//以下判断目前的数是否已经判断过
		for (int j = 0; j < unhappy.size(); j++)
		{
			if (i == unhappy[j])
			{
				searched = 1;
				break;
			}
		}
		if (searched)
		{
			searched = 0;
			continue;
		}
		else
		{
			for (int j = 0; j < happy.size(); j++)
			{
				if (i == happy[j])
				{
					searched = 1;
					break;
				}
			}
			if (searched)
			{
				searched = 0;
				continue;
			}
		}

		//以下正式开始判断该数是什么数，分成计算和判断两步，目前是计算
		vector<int> digit;
		int num = i;
Again:
		int tmp = 0;
		digit.clear();
		while (num) //拆分数字，并放入容器digit
		{
			int j = num % 10;
			digit.push_back(j);
			num /= 10;
		}
		for (int j = 0; j < digit.size(); j++) //各位平方相加
		{
			tmp += digit[j] * digit[j];
		}

		//以下开始判断
		if (tmp == 1)
		{
			unhappy.push_back(i);
			unhappy.insert(unhappy.end(), marked.begin(), marked.end());
			marked.clear();
			continue;
		}
		else if (tmp == i)
		{
			happy.push_back(i);
			happy.insert(happy.end(), marked.begin(), marked.end());
			marked.clear();
			continue;
		}
		for (int j = 0; j < marked.size(); j++)
		{
			if (tmp == marked[j])
			{
				happy.push_back(i);
				happy.insert(happy.end(), marked.begin(), marked.end());
				marked.clear();
				markedOver = 1;
				break;
			}
		}
		if (markedOver)
		{
			markedOver = 0;
			continue;
		}
		marked.push_back(tmp);
		if (!marked.size()) marked.push_back(tmp);
		num = tmp;
		goto Again;
	}
	sort(unhappy.begin(), unhappy.end());
	sort(happy.begin(), happy.end());
	unhappy = EraseRepeat(unhappy);
	happy = EraseRepeat(happy);
	cout << "忧伤数如下：" << endl;
	for (int i = 0; i < unhappy.size(); i++)
	{
		cout << unhappy[i] << "、";
	}
	cout << endl << "幸福数如下：" << endl;
	for (int i = 0; i < happy.size(); i++)
	{
		cout << happy[i] << "、";
	}
	return 0;
}