
#include <iostream>
#include <vector>
#include <list>
#include <chrono>

int main() 
{
    const int N =100000; // 插入元素的数量 
    std::vector<int> vec;// 使用vector进行插入操作
    auto startVec = std::chrono::high_resolution_clock::now();
    for (int i =0; i < N; i++) 
    {
    vec.insert(vec.begin() + i /2, i);
    }
    auto endVec = std::chrono::high_resolution_clock::now();
     auto durationVec = std::chrono::duration_cast<std::chrono::milliseconds>(endVec - startVec);
    std::cout << "使用vector插入" << N << "个元素所需时间：" << durationVec.count() << " 毫秒" << std::endl; // 使用list进行插入操作


     std::list<int> lst;
    auto startLst = std::chrono::high_resolution_clock::now();
     for (int i =0; i < N; i++) 
     {
    lst.insert(std::next(lst.begin(), i /2), i);
    }
    auto endLst = std::chrono::high_resolution_clock::now();
    auto durationLst = std::chrono::duration_cast<std::chrono::milliseconds>(endLst - startLst);
    std::cout << "使用list插入" << N << "个元素所需时间：" << durationLst.count() << " 毫秒" << std::endl;
}