#include <iostream>
#include <vector>
#include <list>
#include <chrono>

int main() 
{
    const int iterations = 10000000; // 插入操作的次数

    // 测试 vector 的插入性能
    std::vector<int> vec;
    auto startVec = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        vec.insert(vec.begin(), i);
    }
    auto endVec = std::chrono::high_resolution_clock::now();
    auto durationVec = std::chrono::duration_cast<std::chrono::milliseconds>(endVec - startVec);
    std::cout << "在 vector 中进行 " << iterations << " 次插入操作所需时间：" << durationVec.count() << " 毫秒\n";

    // 测试 list 的插入性能
    std::list<int> lst;
    auto startLst = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        lst.insert(lst.begin(), i);
    }
    auto endLst = std::chrono::high_resolution_clock::now();
    auto durationLst = std::chrono::duration_cast<std::chrono::milliseconds>(endLst - startLst);
    std::cout << "在 list 中进行 " << iterations << " 次插入操作所需时间：" << durationLst.count() << " 毫秒\n";

    return 0;
}