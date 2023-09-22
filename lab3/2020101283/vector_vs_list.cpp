#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
using namespace std;

const int Begin_num = 10000;
const int Insert_num = 10000;


double begin_time, end_time;

int main()
{
	cout << "当前初始容量：" << Begin_num << "，" << "插入数量：" << Insert_num << endl;
	
	//计算vector插入用时
	vector<int> my_vector(Begin_num);
	begin_time = clock();//获取开始时间 
	for (int j = 0; j < Insert_num; j++) 
		my_vector.insert(my_vector.begin() + (rand() % my_vector.size()), 1);
	end_time = clock();//获取结束时间
	cout << "vector用时（ms）："; 
	cout << (double)((end_time - begin_time) / 1000) << endl;
	
	
	//计算list插入用时
	list<int> my_list(Begin_num);
	list<int>::iterator it;
	it = my_list.begin();
	begin_time = clock();//获取开始时间 
	for (int j = 0; j < Insert_num; j++)
	{
		for (int i = 0; i < rand(); i ++) it ++;
		my_list.insert(it, 1);
	}
	end_time = clock();//获取结束时间 
	cout << "list用时（ms）："; 
	cout << (double)((end_time - begin_time) / 1000) << endl;
}
