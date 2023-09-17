#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

std::vector<int>vec(50);
std::list<int>li(50);

int main()
{
	int testnum;
	srand((unsigned int)time(nullptr));
	cout << "������ͨ���������һ��������Ԫ�����Ƚ�vector��list�����ܲ���" << endl;
	cout << "������Ҫ�����Ԫ����������Ҫ����90000����������㣩��";
	cin >> testnum;
	// ������size()��Ա���������ʱ��ķѣ�
	// ���½����׼ȷ��Ӧ�ֶ�����
	size_t size = 50;

	clock_t start = clock();
	clock_t vector_time = 0;
	clock_t list_time = 0;
	
	// ��vector�����λ�ò���n��Ԫ�ز��Ƚ�
	// ȡģ��Ϊ�����Ʒ�Χ����ֹԽ��
	auto iter_vec = vec.begin();
	for (int i = 0; i < testnum; i++)
	{
		advance(iter_vec, rand() % (size - 1));//����ƶ�������
		vec.insert(iter_vec, 0);
		++size;
		iter_vec = vec.begin();//�������ص�ͷ��
	}
	vector_time = clock() - start;

	start = clock();
	size = 50;
	auto iter_li = li.begin();
	for (int i = 0; i < testnum; i++)
	{
		advance(iter_li, rand() % (size - 1));
		li.insert(iter_li, 0);
		++size;
		iter_li = li.begin();
	}
	list_time = clock() - start;
	
	cout << "Vector time: " << vector_time << "ms" << endl;
	cout << "List time: " << list_time << "ms" << endl;
}