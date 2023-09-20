#include <iostream>
#include <unordered_set>

using namespace std;

// 计算一个数的平方和
int calculateSquareSum(int n) {
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

// 判断一个数是否是忧伤数
bool isSadNumber(int n) {
    unordered_set<int> seenNumbers;

    while (true) {
        int squareSum = calculateSquareSum(n);

        if (squareSum == 1)
            return false;

        if (seenNumbers.count(squareSum) > 0)
            return true;

        seenNumbers.insert(squareSum);
        n = squareSum;
    }
}

int main() {
    cout << "幸福的数：" << endl;
    for (int i = 1; i <= 1000; i++) {
        if (!isSadNumber(i))
            cout << i << " ";
    }
    cout << endl;

    cout << "忧伤的数：" << endl;
    for (int i = 1; i <= 1000; i++) {
        if (isSadNumber(i))
            cout << i << " ";
    }
    cout << endl;

    return 0;
}