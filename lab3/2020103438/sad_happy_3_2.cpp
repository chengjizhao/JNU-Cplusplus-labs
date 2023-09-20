#include <iostream>
#include <vector>

using namespace std;

// 计算一个数是否是“幸福数”
int calculate_happiness(int n) {
    while (n != 1 && n != 4) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        n = sum; // 更新n为新的和
    }
    return n == 1; // 如果n最终等于1，则返回true，否则返回false
}

int main() {
    vector<int> happy_numbers; // 存储幸福数的容器
    vector<int> sad_numbers;   // 存储忧伤数的容器

    // 遍历从1到1000的所有整数
    for (int num = 1; num <= 1000; ++num) {
        if (calculate_happiness(num)) {
            happy_numbers.push_back(num); // 是幸福数添加到幸福数容器中
        } else {
            sad_numbers.push_back(num);   // 否则添加到忧伤数容器
        }
    }

    cout << "幸福数:" << endl;
    for (int num : happy_numbers) {
        cout << num << " "; // 所有幸福数
    }
    cout << endl;

    cout << "忧伤数:" << endl;
    for (int num : sad_numbers) {
        cout << num << " "; // 所有忧伤数
    }
    cout << endl;

    return 0;
}