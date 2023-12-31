#include <algorithm>
#include <cmath>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;
mutex mtx;

void find_prime(int from, int to,vector<int>* v) {
  int i, j;
  for (i = max(from, 2); i <= to; ++i) {
    for (j = 2; j <= sqrt(i); ++j) {
      if (i % j == 0) break;
    }

    if (j > sqrt(i)) {
      mtx.lock();
      v->push_back(i);
      mtx.unlock();
    }
  }
}

int main() {
 thread threads[10];
 vector<int> result;
  for (int i = 0; i < 10; ++i) 
  {

    threads[i] = thread(find_prime, 1000 * i / 10 + 1, 1000 * (i + 1) / 10, &result);
  }

  for (int i = 0; i < 10; ++i) 
  {
    threads[i].join();
  }

  sort(result.begin(), result.end(), [](int a, int b) { return a < b; });

  for (int i = 1; i <= result.size(); ++i) {
   cout << result[i - 1] << "\t";
    if (i % 10 == 0) cout << "\n";
  }
}