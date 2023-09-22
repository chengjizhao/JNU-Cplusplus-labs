
#include <iostream>
#include <vector>
#include <list>
#include <chrono>

int main() {
    const int numElements = 1000000;
    
    // 使用vector进行随机插入，并计算时间
    auto startVector = std::chrono::steady_clock::now();
    std::vector<int> myVector;
    for (int i = 0; i < numElements; ++i) {
        myVector.insert(myVector.begin() + i, i);
    }
    auto endVector = std::chrono::steady_clock::now();
    
    // 使用list进行随机插入，并计算时间
    auto startList = std::chrono::steady_clock::now();
    std::list<int> myList;
    for (int i = 0; i < numElements; ++i) {
        myList.insert(myList.begin(), i);
    }
    auto endList = std::chrono::steady_clock::now();

    // 计算时间差并输出结果
    std::chrono::duration<double> timeVector = endVector - startVector;
    std::chrono::duration<double> timeList = endList - startList;

    std::cout << "Vector插入时间: " << timeVector.count() << " 秒" << std::endl;
    std::cout << "List插入时间: " << timeList.count() << " 秒" << std::endl;

    return 0;
}
