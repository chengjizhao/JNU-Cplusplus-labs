#include <iostream>
#include <unordered_set>

// 计算一个数字的平方和
int squareSum(int num) {
    int sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }
    return sum;
}

// 判断一个数字是否是忧伤数
bool isSadNumber(int num) {
    std::unordered_set<int> visited;

    while (num != 1 && visited.find(num) == visited.end()) {
        visited.insert(num);
        num = squareSum(num);
    }

    return num == 1;
}

int main() {
    std::cout << "Happy numbers: ";
    for (int i = 1; i <= 1000; ++i) {
        if (!isSadNumber(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";

    std::cout << "Sad numbers: ";
    for (int i = 1; i <= 1000; ++i) {
        if (isSadNumber(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";

    return 0;
}