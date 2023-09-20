#include <iostream>
#include <vector>
#include <list>
#include <chrono>  // 用于测量时间

int main() {
    const int num_elements = 100000;  // 要插入的元素数量

    // 测试 std::vector 的性能
    {
        std::vector<int> vec;
        
        auto start = std::chrono::high_resolution_clock::now();  // 记录开始时间

        // 随机插入元素
        for (int i = 0; i < num_elements; ++i) {
            int pos = rand() % (vec.size() + 1);  // 随机选择插入位置
            vec.insert(vec.begin() + pos, i);
        }

        auto end = std::chrono::high_resolution_clock::now();  // 记录结束时间
        std::chrono::duration<double> duration = end - start;  // 计算耗时
        std::cout << "std::vector 插入 " << num_elements << " 个元素所用时间: " << duration.count() << " 秒\n";
    }

    // 测试 std::list 的性能
    {
        std::list<int> lst;

        auto start = std::chrono::high_resolution_clock::now();  // 记录开始时间

        // 随机插入元素
        for (int i = 0; i < num_elements; ++i) {
            auto it = lst.begin();
            std::advance(it, rand() % lst.size());  // 随机选择插入位置
            lst.insert(it, i);
        }

        auto end = std::chrono::high_resolution_clock::now();  // 记录结束时间
        std::chrono::duration<double> duration = end - start;  // 计算耗时
        std::cout << "std::list 插入 " << num_elements << " 个元素所用时间: " << duration.count() << " 秒\n";
    }

    return 0;
}
