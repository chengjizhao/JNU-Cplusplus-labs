#include <iostream>
#include <unordered_set>

int SquareSum(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool HappyNumber(int n) {
    std::unordered_set<int> visited;
    while (true) {
        int squareSum = SquareSum(n);
        if (squareSum == 1) {
            return true;  // 幸福数
        }
        if (visited.count(squareSum)) {
            return false;  // 忧伤数
        }
        visited.insert(squareSum);
        n = squareSum;
    }
}

int main() {
    std::cout << "幸福的数：" << std::endl;
    for (int i = 1; i <= 1000; ++i) {
        if (HappyNumber(i)) {
            std::cout << i << " ";
        }
    }

    std::cout << "\n\n忧伤的数：" << std::endl;
    for (int i = 1; i <= 1000; ++i) {
        if (!HappyNumber(i)) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
