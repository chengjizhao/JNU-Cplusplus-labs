#include <iostream>
#include <vector>

using namespace std;

// 计算一个数是否是“幸福数”
int calculateHappiness(int n) {
    while (n != 1 && n != 4) {
        int sum = 0;
        // 将数的每个位上的数字的平方相加
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
    vector<int> happyNumbers; // 存储幸福数的容器
    vector<int> sadNumbers;   // 存储忧伤数的容器

    // 遍历从1到1000的所有整数
    for (int num = 1; num <= 1000; ++num) {
        if (calculateHappiness(num)) {
            happyNumbers.push_back(num); // 如果是幸福数，将其添加到幸福数容器中
        } else {
            sadNumbers.push_back(num);   // 否则将其添加到忧伤数容器中
        }
    }

    cout << "幸福的数:" << endl;
    for (int num : happyNumbers) {
        cout << num << " "; // 输出所有幸福数
    }
    cout << endl;

    cout << "忧伤的数:" << endl;
    for (int num : sadNumbers) {
        cout << num << " "; // 输出所有忧伤数
    }
    cout << endl;

    return 0;
}
