#include <iostream>
#include <unordered_set>
using namespace std;

// 计算一个数字的平方和
int calculateSquareSum(int n) {
    int sum = 0;
    while (n != 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

// 判断一个数是幸福数还是忧伤数
bool isUnhappy(int n) {
    unordered_set<int> visited;
    while (n != 1 && visited.find(n) == visited.end()) {
        visited.insert(n);
        n = calculateSquareSum(n);
    }
    return n == 1;
}

int main() {
    cout << "幸福数:\n";
    for (int i = 1; i <= 1000; ++i) {
        if (!isUnhappy(i)) {
            cout << i << " ";
        }
    }
    cout << "\n\n忧伤数:\n";
    for (int i = 1; i <= 1000; ++i) {
        if (isUnhappy(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
