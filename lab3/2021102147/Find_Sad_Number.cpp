#include <iostream>
#include <vector>

using std::cin, std::cout, std::endl, std::vector;

bool isSad(int n)
{
	vector<int>already;
	vector<int>::iterator it;
	while (n != 1)
	{
		int sum = 0;
		while (n > 0)
		{
			sum += (n % 10) * (n % 10);
			n /= 10;
		}
		it = std::find(already.begin(), already.end(), sum);
		if ( it != already.end())
		{
			return false;
		}
		n = sum;
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
