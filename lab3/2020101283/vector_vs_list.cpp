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
	cout << "��ǰ��ʼ������" << Begin_num << "��" << "����������" << Insert_num << endl;
	//vector
	vector<int> my_vector(Begin_num);
		begin_time = clock();//��ȡ��ʼʱ�� 
		for (int j = 0; j < Insert_num; j++) 
			my_vector.insert(my_vector.begin() + (rand() % my_vector.size()), 1);
		end_time = clock();//��ȡ����ʱ��
		cout << "vector��ʱ��ms����"; 
		cout << (double)((end_time - begin_time) / 1000) << endl;
	
	
	//list
	list<int> my_list(Begin_num);
		list<int>::iterator it;
		it = my_list.begin();
		begin_time = clock();//��ȡ��ʼʱ�� 
		for (int j = 0; j < Insert_num; j++)
		{
			for (int i = 0; i < rand(); i ++) it ++;
			my_list.insert(it, 1);
		}
		end_time = clock();//��ȡ����ʱ�� 
		cout << "list��ʱ��ms����"; 
		cout << (double)((end_time - begin_time) / 1000) << endl;
}
