#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>

int main() {
    const int numElements = 100000; // 要插入的元素数量
    std::vector<int> vec;
    std::list<int> lst;

    // 向vector插入元素并测量时间
    std::clock_t start = std::clock();
    for (int i = 0; i < numElements; ++i) {
        int randomPos = rand() % (i + 1);
        vec.insert(vec.begin() + randomPos, i);
    }
    std::clock_t end = std::clock();
    double vectorTime = double(end - start) / CLOCKS_PER_SEC;

    // 向list插入元素并测量时间
    start = std::clock();
    for (int i = 0; i < numElements; ++i) {
        int randomPos = rand() % (i + 1);
        auto it = lst.begin();
        std::advance(it, randomPos);
        lst.insert(it, i);
    }
    end = std::clock();
    double listTime = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "向vector插入 " << numElements << " 个元素所需时间: " << vectorTime << " 秒\n";
    std::cout << "向list插入 " << numElements << " 个元素所需时间: " << listTime << " 秒\n";

    return 0;
}