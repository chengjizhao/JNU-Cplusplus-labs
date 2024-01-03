#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()

{
	vector<int> v;
	list<int> l;

	for (int i = 0; i < 8; i++) //往v和l中分别添加元素
	{

		v.push_back(i);
		l.push_back(i);

	}

	cout << "v[2] = " << v[2] << endl;
	cout << (v.begin() < v.end()) << endl;
	cout << *(v.begin() + 1) << endl;

	vector<int>::iterator itv = v.begin();
	list<int>::iterator itl = l.begin();

	itv = itv + 2;
	itl++; itl++;
	cout << *itv << endl;
	cout << *itl << endl;

	return 0;

}