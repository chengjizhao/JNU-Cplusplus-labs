#include <iostream>

using std::cin,std::cout,std::endl;

bool isSad(int n)
{
	while (n >= 10)
	{
		int sum = 0;
		while (n > 0)
		{
			sum += (n % 10)*(n % 10);
			n /= 10;
		}
		n = sum;
	}
	return n == 1;
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
