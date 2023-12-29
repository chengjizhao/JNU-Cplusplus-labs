
#pragma once
#include <vector>
#include <mutex>

extern std::mutex g_mutex;
extern std::vector<int> g_primeNumbers;

bool isPrime(int n);
void calculatePrimesInRange(int start, int end);