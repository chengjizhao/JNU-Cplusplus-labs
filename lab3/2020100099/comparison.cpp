#include <iostream>
#include <vector>
#include <list>
#include <ctime>

const int NUM_ELEMENTS = 1000000;

int main() {
    std::vector<int> vec;
    std::list<int> lst;

    // 测量向 vector 插入元素的耗时
    clock_t start = clock();
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        vec.insert(vec.begin() + rand() % (vec.size() + 1), i);
    }
    clock_t end = clock();

    std::cout << "向 vector 插入元素的耗时：" << double(end - start) / CLOCKS_PER_SEC << " 秒" << std::endl;

    // 清空 vector
    vec.clear();

    // 测量向 list 插入元素的耗时
    start = clock();
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        lst.insert(lst.begin(), i);
    }
    end = clock();

    std::cout << "向 list 插入元素的耗时：" << double(end - start) / CLOCKS_PER_SEC << " 秒" << std::endl;

    return 0;
}