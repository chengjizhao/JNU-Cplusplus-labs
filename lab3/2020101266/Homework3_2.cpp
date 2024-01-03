#include<iostream>
#include<vector>
#include<set>

using namespace std;
int myarray[10001];

bool isPrimeNumer(int num)//�ж��Ƿ�����
{
	for (int i = 2; i * i <= num; ++i)//ע����С�ڵ���
	{
		if (num % i == 0)//���磬����8
			return false;
	}
	return true;
}

bool isLeafe(int num, int from, int to)//�ж��Ƿ�ΪҶ���������ͼʾ���
{
	for (int i = from; i <= to; ++i)
	{
		if (num == myarray[i])//�ж��Ƿ���������ָ��
			return false;
	}
	return true;
}

int calculate(int num)//����һ�����֣����������λ���ϵ�����ƽ����
{
	int sum = 0;
	while (num != 0)
	{
		sum += (num % 10) * (num % 10);
		num /= 10;
	}
	return sum;
}

int find_roof(int num)//�ҵ�num���ֶ�Ӧ�ĸ���������Ľ��Ϊ1����֤���ɹ��ҵ��Ҹ���
{
	set<int> myset;
	pair<set<int>::iterator, bool> ret;//����insert�ķ���ֵ�н�
	while (myarray[num] != num)
	{
		ret = myset.insert(myarray[num]);
		if (ret.second == false)
			return -1;//֤������ѭ���������Ҹ�����
		num = myarray[num];

	}
	return num;//һ�����������ֵ�ƽ������Ϊ�䱾���Ǿ���1������
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
		myarray[i] = calculate(i);//��ʼ��Ϊi��Ӧֵ��ƽ��
	}
	int temp = 0;
	for (int i = from; i <= to; ++i)
	{
		if (isLeafe(i, from, to) && find_roof(i) == 1)//��ȷ��Ҷ��ͬʱ��Ҷ����ָ���
		{
			temp++;
			cout << i << " ";
			int flag = 1, x = i;
			while (calculate(x) != 1)//�����������
			{
				x = calculate(x);
				flag++;
			}
			if (isPrimeNumer(i))flag *= 2; //�˴����Ҹ��������ж��Ƿ���������
			cout << flag << endl;
		}
	}
	if (temp == 0)
	{
		cout << "SAD" << endl;
	}
	return 0;
}