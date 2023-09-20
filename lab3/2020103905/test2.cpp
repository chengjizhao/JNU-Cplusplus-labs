#include <iostream>
#include <unordered_set>

// 计算数字的平方和
int calculateSquareSum(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

// 判断一个数是幸福数还是忧伤数
bool isHappyNumber(int n) {
    std::unordered_set<int> seen; // 用于存储已经出现过的数字
    while (n != 1 && !seen.count(n)) { // 当数字不为1且未出现过时，继续拆分求平方和
        seen.insert(n);
        n = calculateSquareSum(n);
    }
    return n == 1;
}

int main() {
    std::cout << "幸福的数：";
    for (int i = 1; i <= 1000; ++i) {
        if (isHappyNumber(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "忧伤的数：";
    for (int i = 1; i <= 1000; ++i) {
        if (!isHappyNumber(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}