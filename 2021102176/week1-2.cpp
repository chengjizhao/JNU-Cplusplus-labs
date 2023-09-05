//使用C++数组时，超出数组边界访问元素，可能导致分段错误。

#include<iostream>
using namespace std;

int main() {
    int arr[5] = { 1, 2, 3, 4, 5 };

    for (int i = 0; i <= 5; i++) { // 超出数组边界
        cout << arr[i] << " ";
    }
    return 0;
}
