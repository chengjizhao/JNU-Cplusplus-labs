#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <vector>
#include <mutex>
#include <algorithm>


std::mutex mtx;

void random_withdraw(std::vector<int>* accounts,int index)
{
	int amount;
	amount = std::abs((rand() - 30) % 100);
	mtx.lock();
	std::cout << "Withdraw $" << amount << " from account " << index << std::endl;
	(*accounts)[index] -= amount;
	std::cout << "Account " << index << " now has $" << (*accounts)[index] << std::endl;
	mtx.unlock();
}

void random_deposit(std::vector<int>* accounts, int index)
{
	int amount;
	amount = rand() % 100;
	mtx.lock();
	std::cout << "Deposit $" << amount << " to account " << index << std::endl;
	(*accounts)[index] += amount;
	std::cout << "Account " << index << " now has $" << (*accounts)[index] << std::endl;
	mtx.unlock();
}

// 以随机时间间隔调用fn函数n次,使用随机参数
void do_something_in_random_period(void (*fn)(std::vector<int>*,int), int n, std::vector<int>* v)
{
	for (int i = 0; i < n; ++i)
	{
		fn(v,rand() % 9);
		std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
	}
}

int main()
{
	srand(time(nullptr));
	std::vector<int> accounts(10, 1000);
	std::thread withdraw_thread(do_something_in_random_period, random_withdraw, 10, &accounts);
	std::thread deposit_thread(do_something_in_random_period, random_deposit, 10, &accounts);
	withdraw_thread.join();
	deposit_thread.join();
	return 0;
}