#include <iostream>
#include <unordered_set>

// 计算一个数字的平方和
int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

// 判断一个数字是否是悲伤的数
bool isSadNumber(int n) {
    std::unordered_set<int> seen;//每判断一个数就会重置一次seen集合，所以下面那步‘seen.find(n) == seen.end()’只是为了防止出现无限循环的情况。
    while (n != 1 && seen.find(n) == seen.end())
    {
        seen.insert(n);
        n = sumOfSquares(n);
    }
    return n == 1; // 如果平方和最终等于1，则是悲伤的数
}

int main() {
    std::cout << "1000以内的悲伤的数有：\n";
    for (int i = 1; i <= 1000; ++i) {
        if (isSadNumber(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";

    std::cout << "1000以内的幸福的数有：\n";
    for (int i = 1; i <= 1000; ++i) {
        if (!isSadNumber(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";

    return 0;
}