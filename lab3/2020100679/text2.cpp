
#include <iostream>
#include <unordered_set>

int calculateSquareSum(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappyNumber(int n) {
    std::unordered_set<int> visited;
    while (true) {
        int squareSum = calculateSquareSum(n);
        if (squareSum == 1)
            return true;
        if (visited.count(squareSum) > 0)
            return false;
        visited.insert(squareSum);
        n = squareSum;
    }
}

int main() {
    std::cout << "忧伤的数：" << std::endl;
    for (int i = 1; i <= 1000; ++i) {
        if (!isHappyNumber(i))
            std::cout << i << " ";
    }

    std::cout << "\n\n幸福的数：" << std::endl;
    for (int i = 1; i <= 1000; ++i) {
        if (isHappyNumber(i))
            std::cout << i << " ";
    }

    return 0;
}
