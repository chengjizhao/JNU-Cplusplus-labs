#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

const int N = 1000;

using namespace std;

//�����ظ�����
vector<int> EraseRepeat(vector<int> vec)
{
	vector<int>::iterator i = unique(vec.begin(), vec.end());
	vec.erase(i, vec.end());
	return vec;
}

int main()
{
	int searched = 0; //��ʾ������Ƿ�������
	int markedOver = 0; //��ʾmarked�����е����Ƿ��ƶ�������������
	vector<int> unhappy; //��������������ͬ��
	vector<int> happy;
	vector<int> marked;
	for (int i = 1; i <= 1000; i++)
	{
		//�����ж�Ŀǰ�����Ƿ��Ѿ��жϹ�
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

		//������ʽ��ʼ�жϸ�����ʲô�����ֳɼ�����ж�������Ŀǰ�Ǽ���
		vector<int> digit;
		int num = i;
Again:
		int tmp = 0;
		digit.clear();
		while (num) //������֣�����������digit
		{
			int j = num % 10;
			digit.push_back(j);
			num /= 10;
		}
		for (int j = 0; j < digit.size(); j++) //��λƽ�����
		{
			tmp += digit[j] * digit[j];
		}

		//���¿�ʼ�ж�
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
	cout << "���������£�" << endl;
	for (int i = 0; i < unhappy.size(); i++)
	{
		cout << unhappy[i] << "��";
	}
	cout << endl << "�Ҹ������£�" << endl;
	for (int i = 0; i < happy.size(); i++)
	{
		cout << happy[i] << "��";
	}
	return 0;
}