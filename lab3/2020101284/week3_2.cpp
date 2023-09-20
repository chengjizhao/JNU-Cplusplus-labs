#include <iostream>
#include <unordered_set>

using namespace std;

// ����һ������ƽ����
int calculateSquareSum(int n) {
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

// �ж�һ�����Ƿ���������
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
    cout << "�Ҹ�������" << endl;
    for (int i = 1; i <= 1000; i++) {
        if (!isSadNumber(i))
            cout << i << " ";
    }
    cout << endl;

    cout << "���˵�����" << endl;
    for (int i = 1; i <= 1000; i++) {
        if (isSadNumber(i))
            cout << i << " ";
    }
    cout << endl;

    return 0;
}