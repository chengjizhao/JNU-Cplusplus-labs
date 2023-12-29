#include "PrimeCalculator.h"
#include <iostream>
#include <thread>
#include <vector>

int main() {
	const int numThreads = 4; // 假设使用 4 个线程
	const int startRange = 1;
	const int endRange = 100;

	std::vector<std::thread> threads;

	int rangeSize = (endRange - startRange + 1) / numThreads;
	for (int i = 0; i < numThreads; ++i) {
		int start = startRange + i * rangeSize;
		int end = (i == numThreads - 1) ? endRange : start + rangeSize - 1;
		threads.push_back(std::thread(calculatePrimesInRange, start, end));
	}

	for (auto& thread : threads) {
		thread.join();
	}

	std::cout << "范围中的素数  ";
	for (int prime : g_primeNumbers) {
		std::cout << prime << " ";
	}
	std::cout << std::endl;

	return 0;
}