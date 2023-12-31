#include <algorithm>
#include <cmath>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex mtx;

void find_prime(int from, int to, std::vector<int>* v) {
  int i, j;
  for (i = std::max(from, 2); i <= to; ++i) {
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
  std::thread threads[10];
  std::vector<int> result;
  for (int i = 0; i < 10; ++i) {
    // 1-1000
    threads[i] = std::thread(find_prime, 1000 * i / 10 + 1, 1000 * (i + 1) / 10,
                             &result);
  }

  for (int i = 0; i < 10; ++i) {
    threads[i].join();
  }

  std::sort(result.begin(), result.end(), [](int a, int b) { return a < b; });

  for (int i = 1; i <= result.size(); ++i) {
    std::cout << result[i - 1] << "\t";
    if (i % 10 == 0) std::cout << "\n";
  }
}