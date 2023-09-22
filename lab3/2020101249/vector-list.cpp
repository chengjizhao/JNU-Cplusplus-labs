#include <iostream>
#include <vector>
#include <list>
#include <chrono>

int main() {
    const int N = 1000000;  // 要插入的元素数量
    std::vector<int> vec;
    auto start = std::chrono::steady_clock::now();  // 记录开始时间
    for (int i = 0; i < N; i++)
    {
        vec.insert(vec.begin() + i/2, i);  // 在当前位置的前一半插入元素
    }
    auto end = std::chrono::steady_clock::now();  // 记录结束时间
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "使用 vector 进行插入操作的时间：" << elapsed_seconds.count() << " 秒\n";
    std::list<int> lst;
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < N; i++) 
    {
        lst.insert(std::next(lst.begin(), i/2), i);
    }
    end = std::chrono::steady_clock::now();
    elapsed_seconds = end - start;
    std::cout << "使用 list 进行插入操作的时间：" << elapsed_seconds.count() << " 秒\n";
    return 0;
}