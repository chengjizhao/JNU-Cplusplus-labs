#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	double begin_time, end_time;
	
	int begin_num, insert_num;
	int a = 6;
	
	while (a)
	{
		switch(a)
		{
			case 6:
				begin_num = 1000;
				insert_num = 1000;
				break;
			case 5:
				begin_num = 10000;
				insert_num = 1000;
				break;
			case 4:
				begin_num = 10000;
				insert_num = 10000;
				break;
			case 3:
				begin_num = 100000;
				insert_num = 10000;
				break;
			case 2:
				begin_num = 100000;
				insert_num = 100000;
				break;
			case 1:
				begin_num = 100000;
				insert_num = 1000;
				break;
		}
		a --;
		cout << "初始容量：" << begin_num << "\n" << "插入数量：" << insert_num << endl;
		
		vector<int> v(begin_num);
		begin_time = clock();
		for (int p = 0; p < insert_num; p++) v.insert(v.begin() + (rand() % v.size()), 1);
		end_time = clock();
		cout << "vector用时（ms）："; 
		cout << (double)((end_time - begin_time) / 1000) << endl;
		
		list<int> l(begin_num);
		list<int>::iterator it;
		it = l.begin();
		begin_time = clock();
		for (int p = 0; p < insert_num; p++)
		{
			for (int i = 0; i < rand(); i ++) it ++;
			l.insert(it, 1);
		}
		end_time = clock();
		cout << "list用时（ms）："; 
		cout << (double)((end_time - begin_time) / 1000) << endl;
		
		cout << "-------------------------" << endl;
	}
	
	return 0;
}