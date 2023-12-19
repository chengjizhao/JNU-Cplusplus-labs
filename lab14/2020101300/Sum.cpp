#include <thread>
#include <vector>

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void sum_of_primes(int start, int end, std::vector<int>& result) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            sum += i;
        }
    }
    result.push_back(sum);
}

int main() {
    std::vector<int> result;
    int start = 1;
    int end = 10000;
    int num_of_threads = 4;
    int step = (end - start + 1) / num_of_threads;
    std::vector<std::thread> threads;
    for (int i = 0; i < num_of_threads; i++) {
        int thread_start = start + i * step;
        int thread_end = start + (i + 1) * step - 1;
        if (i == num_of_threads - 1) {
            thread_end = end;
        }
        std::thread thread(sum_of_primes, thread_start, thread_end, std::ref(result));
        threads.push_back(std::move(thread));
        thread.detach();
    }
    for (auto& thread : threads) {
        thread.join();
    }
    int total = 0;
    for (auto& sum : result) {
        total += sum;
    }
    std::cout << "The sum of primes from " << start << " to " << end << " is " << total << ".\n";
    return 0;
}
