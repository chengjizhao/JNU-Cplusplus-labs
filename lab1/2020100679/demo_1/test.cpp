#include <iostream>

int main() {
    int* ptr = nullptr;
    *ptr = 10; // 尝试在空指针上进行写操作
    return 0;
}