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
	cout << "本程序通过随机插入一定数量的元素来比较vector和list的性能差异" << endl;
	cout << "请输入要插入的元素数量（不要大于90000，否则等死你）：";
	cin >> testnum;
	// 容器的size()成员函数会产生时间耗费，
	// 导致结果不准确，应手动计算
	size_t size = 50;

	clock_t start = clock();
	clock_t vector_time = 0;
	clock_t list_time = 0;
	
	// 在vector的随机位置插入n个元素并比较
	// 取模是为了限制范围，防止越界
	auto iter_vec = vec.begin();
	for (int i = 0; i < testnum; i++)
	{
		advance(iter_vec, rand() % (size - 1));//随机移动迭代器
		vec.insert(iter_vec, 0);
		++size;
		iter_vec = vec.begin();//迭代器回到头部
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