#include <iostream>
#include <unordered_set>
// 函数用于计算给定数字的下一个数
int getNextNumber(int n) 
{
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}
// 函数用于判断一个数字是忧伤数还是幸福数
bool isHappy(int n) {
    std::unordered_set<int> seen;  // 用于存储已经出现过的数字，以检测循环
    while (n != 1 && seen.find(n) == seen.end())
    {
        seen.insert(n);
        n = getNextNumber(n);
    }
    return n == 1;
}

int main()
 {
    std::cout << "幸福的数（Happy Numbers）：" << std::endl;
    for (int i = 1; i <= 1000; ++i) {
        if (isHappy(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "忧伤的数（Sad Numbers）：" << std::endl;
    for (int i = 1; i <= 1000; ++i) {
        if (!isHappy(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}