#include <iostream>
#include <vector>
#include <list>
#include <chrono>

int main() {
    const int N = 1000000;
    
    // 使用 vector 进行随机插入测试
    std::vector<int> vec;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        vec.insert(vec.begin() + i/2, i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Vector insertion time: " << duration.count() << " seconds" << std::endl;
    
    // 使用 list 进行随机插入测试
    std::list<int> lis;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        auto it = lis.begin();
        std::advance(it, i/2);
        lis.insert(it, i);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "List insertion time: " << duration.count() << " seconds" << std::endl;
    
    return 0;
}