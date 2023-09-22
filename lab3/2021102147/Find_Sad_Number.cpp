#include <iostream>
#include <algorithm>
#include <vector>

using std::cin, std::cout, std::endl, std::vector;

bool isSad(int n)
{
	vector<int>already;
	vector<int>::iterator it;
	while (n != 1)// 当最后的结果为1时，是悲伤数
	{
		int sum = 0;
		while (n > 0)
		{
			sum += (n % 10) * (n % 10);// 通过取余运算取末位并平方、累加
			n /= 10; //去掉末位
		}
		// 找一下当前的和(sum)有没有出现过（防止死循环）
		it = std::find(already.begin(), already.end(), sum);
		if (it != already.end())
		{
			return false;
		}
		n = sum;// 把sum作为下一次运算的数字
		already.push_back(sum);
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
