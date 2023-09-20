#include <iostream>
#include <unordered_set>  // 用于存储幸福和忧伤的数

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

// 判断一个数字是否是忧伤的数
bool isUnhappyNumber(int n) {
    // 使用集合来检查是否陷入循环，如果陷入循环则为忧伤的数
    std::unordered_set<int> visited;
    
    while (n != 1 && visited.find(n) == visited.end()) {
        visited.insert(n);
        n = calculateSquareSum(n);
    }

    return n != 1;
}

int main() {
    std::cout << "幸福的数：\n";
    for (int i = 1; i <= 1000; ++i) {
        if (!isUnhappyNumber(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";

    std::cout << "忧伤的数：\n";
    for (int i = 1; i <= 1000; ++i) {
        if (isUnhappyNumber(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";

    return 0;
}
