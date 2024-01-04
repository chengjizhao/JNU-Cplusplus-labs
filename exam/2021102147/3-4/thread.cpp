#include "SampleClass.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <thread>
#include <mutex>
#include <ctime>

std::queue<int>q;
int count = 0;


void producer()
{
	std::mutex lk;
	while (true)
	{
		if (count <= 17)
		{
			lk.lock();
			q.push(1);
			q.push(2);
			q.push(3);
			count += 3;
			printf("Producer push: %d %d %d\n",1,2,3);
			lk.unlock();
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		
	}
}

void comsumer()
{
	std::mutex lk;
	while (true)
	{
		if (count > 0)
		{
			lk.lock();
			std::cout << "Comsumer pop: " << q.front() << std::endl;
			q.pop();
			count--;
			lk.unlock();
			std::this_thread::sleep_for(std::chrono::seconds(rand() % 2 + 1));
		}
		
	}
}

int main()
{
	srand(time(nullptr));
	std::thread pts[4];

	for (int i = 0; i < 4; ++i)
	{
		pts[i] = std::thread(producer);
	}
	std::thread ct(comsumer);
	ct.join();
}