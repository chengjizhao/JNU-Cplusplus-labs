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
		 advance(iter, rand() % (size - 1));//����ƶ�������
		 container.insert(iter, 0);
		 ++size;
		 iter = container.begin();//�������ص�ͷ��
	 }
	 return clock() - start;
}


int main()
{
	list<int>li(50);
	vector<int>vec(50);
	deque<int>dq(50);

	int amount;
	cout << "������ͨ���������һ��������Ԫ�����Ƚϲ����������������ܲ���\n";
	cout << "������Ҫ�����Ԫ����������Ҫ����90000����������㣩��";
	cin >> amount;
	
	cout << "Vector time: " << calculate_time(vec, amount) << "ms\n";
	cout << "List time: " << calculate_time(li, amount) << "ms\n";
	cout << "Deque time: " << calculate_time(dq, amount) << "ms\n";
	return 0;
}