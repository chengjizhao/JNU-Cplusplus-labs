#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;
mutex mtx;
void random1(std::vector<int>* accounts, int index) 
{
  int amount;
  amount = rand() % 100;
  mtx.lock();
  std::cout << "存钱" << amount << "账户" << index << std::endl;
  (*accounts)[index] += amount;
  std::cout << "账户 " << index << " 余额" << (*accounts)[index]
            << std::endl;
  mtx.unlock();
}

void random2(std::vector<int>* accounts, int index)
 {
  int amount;
  amount = std::abs((rand()-30) % 100);
  mtx.lock();
  std::cout << "取出" << amount << "账户" << index << std::endl;
  (*accounts)[index] -= amount;
  std::cout << "账户" << index << "余额" << (*accounts)[index]
            << std::endl;
  mtx.unlock();
}



void random_period(void (*t)(std::vector<int>*, int), int n,std::vector<int>* v) 
{
  for (int i = 0; i < n; ++i) {
    t(v, rand()%9);
    std::this_thread::sleep_for(std::chrono::milliseconds(rand()%100));
  }
}

int main() 
{
  srand(time(nullptr));
  std::vector<int> accounts(10, 1000);
  std::thread w(random_period, random1, 10, &accounts);
  std::thread w1(random_period, random2, 10, &accounts);
  w.join();
  w1.join();
  return 0;
}