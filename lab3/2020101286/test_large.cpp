#include <iostream>
#include <vector>
#include <list>
#include <chrono>

// 测试向量对大量元素随机插入的性能
void testVectorInsertlarge() 
{
    std::vector<int> vec;
    auto start = std::chrono::steady_clock::now();
    
    for (int i = 0; i < 100000; i++) 
    {
        vec.insert(vec.begin() + i / 2, i);
    }
    
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;
    
    std::cout << "向量大量元素随机插入耗时: " << duration.count() << " 秒\n";
}

// 测试列表对大量元素随机插入的性能
void testListInsertlarge() 
{
    std::list<int> lst;
    auto start = std::chrono::steady_clock::now();
    
    for (int i = 0; i < 100000; i++) 
    {
        lst.insert(lst.begin(), i);
    }
    
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;
    
    std::cout << "列表大量元素随机插入耗时: " << duration.count() << " 秒\n";
}

int main() 
{
    testVectorInsertlarge();
    testListInsertlarge();
    return 0;
}

//当大量元素随机插入时，向量比列表耗时短很多