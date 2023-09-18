#include <iostream>
#include <vector>

using namespace std;

int calculateHappiness(int n) {
    while (n != 1 && n != 4) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        n = sum;
    }
    return n == 1;
}

int main() {
    vector<int> happyNumbers;
    vector<int> sadNumbers;

    for (int num = 1; num <= 1000; ++num) {
        if (calculateHappiness(num)) {
            happyNumbers.push_back(num);
        } else {
            sadNumbers.push_back(num);
        }
    }

    cout << "幸福的数:" << endl;
    for (int num : happyNumbers) {
        cout << num << " ";
    }
    cout << endl;

    cout << "忧伤的数:" << endl;
    for (int num : sadNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
