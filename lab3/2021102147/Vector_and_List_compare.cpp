#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <cstdlib>

std::vector<int>vec(50);
std::list<int>li(50);

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::vector;

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
	// ��vector�����λ�ò���1000��Ԫ�ز��Ƚ�
	// ȡģ��Ϊ�����Ʒ�Χ����ֹԽ��
	for (int i = 0; i < testnum; i++)
	{
		vec.insert((vec.begin() + (rand() % (size - 1))), 0);
		++size;
	}
	vector_time = clock() - start;

	// list������ͬ�����洢�����ݲ�����������ʹ�üӷ�����λ
	start = clock();
	size = 50;
	auto iter = li.begin();
	for (int i = 0; i < testnum; i++)
	{
		advance(iter, rand() % (size - 1));//����ƶ�������
		li.insert(iter, 0);
		++size;
		iter = li.begin();//�������ص�ͷ��
	}
	list_time = clock() - start;
	cout << "Vector time: " << vector_time << "ms" << endl;
	cout << "List time: " << list_time << "ms" << endl;
}