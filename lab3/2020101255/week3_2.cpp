#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int s_sum(int n)
{
	int n1, n2, n3, n4, s;
	n1 = n % 10;
	n2 = (n / 10) % 10;
	n3 = (n / 100) % 10;
	n4 = n / 1000;
	s = n1 * n1 + n2 * n2 + n3 * n3 + n4 * n4;
	return s;
}

int main()
{
	int n, s, flag;
	vector<int> square_sum;
	set<int> sad;
	set<int> happy;
	vector<int>::iterator loc;
	
	for (n = 1; n <= 1000; n ++)
	{
		square_sum.clear();
		flag = 1;
		s = s_sum(n);
		while (flag)
		{
			if (s == 1)
			{
				flag = 0;
				sad.insert(n);
			}
			else
			{
				loc = find(square_sum.begin(), square_sum.end(), s);
				//s在square_sum里重复 
				if (loc - square_sum.end())
				{
					flag = 0;
					happy.insert(n);
				}
				else
				{
					square_sum.push_back(s);
					s = s_sum(s);
				}	
			}
		}
	}
	for (int x:sad) cout << x << " ";
	cout << "\n忧伤的数共有" << sad.size() << "个" << endl;
	cout << "\n";
	for (int x:happy) cout << x << " ";
	cout << "\n幸福的数共有" << happy.size() << "个" << endl;
	return 0;
}
