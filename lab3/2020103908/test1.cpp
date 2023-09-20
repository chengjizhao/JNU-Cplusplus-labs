#include <iostream>
#include <unordered_set>

// 计算给定数字的平方和
int calculateSquareSum(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

// 判断一个数字是否为幸福数
bool isHappy(int n) {
    std::unordered_set<int> seen;
    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        n = calculateSquareSum(n);
    }
    return n == 1;
}

int main() {
    int limit = 1000;

    std::cout << "忧伤数（Sad Numbers）:" << std::endl;
    for (int i = 1; i <= limit; ++i) {
        if (isHappy(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "幸福数（Happy Numbers）:" << std::endl;
    for (int i = 1; i <= limit; ++i) {
        if (!isHappy(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
