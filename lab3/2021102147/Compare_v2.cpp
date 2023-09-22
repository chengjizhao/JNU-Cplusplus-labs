#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <ctime>
#include <deque>

using std::cin, std::cout, std::vector, std::list, std::deque;

template<typename T>
 clock_t calculate_time(T &container, size_t amount)
{
	 srand((unsigned int)time(nullptr));

	 size_t size = container.size();
	 auto iter = container.begin();

	 clock_t start = clock();
	 for (int i = 0; i < amount; i++)
	 {
		 advance(iter, rand() % (size - 1));//随机移动迭代器
		 container.insert(iter, 0);
		 ++size;
		 iter = container.begin();//迭代器回到头部
	 }
	 return clock() - start;
}


int main()
{
	list<int>li(50);
	vector<int>vec(50);
	deque<int>dq(50);

	int amount;
	cout << "本程序通过随机插入一定数量的元素来比较部分序列容器的性能差异\n";
	cout << "请输入要插入的元素数量（不要大于90000，否则等死你）：";
	cin >> amount;
	
	cout << "Vector time: " << calculate_time(vec, amount) << "ms\n";
	cout << "List time: " << calculate_time(li, amount) << "ms\n";
	cout << "Deque time: " << calculate_time(dq, amount) << "ms\n";
	return 0;
}