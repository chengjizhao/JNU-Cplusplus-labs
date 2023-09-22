#include <iostream>
#include <vector>
#include <list>
#include <chrono>

// 测试向量对少量元素随机插入的性能
void testVectorInsertsmall() 
{
    std::vector<int> vec;
    auto start = std::chrono::steady_clock::now();
    
    for (int k = 0; k < 100; k++) 
    {
        vec.insert(vec.begin() + k / 2, k);
    }
    
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;
    
    std::cout << "向量少量元素随机插入耗时: " << duration.count() << " 秒\n";
}

// 测试列表对少量元素随机插入的性能
void testListInsertsmall() 
{
    std::list<int> lst;
    auto start = std::chrono::steady_clock::now();
    
    for (int k = 0; k < 100; k++) 
    {
        lst.insert(lst.begin(), k);
    }
    
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;
    
    std::cout << "列表少量元素随机插入耗时: " << duration.count() << " 秒\n";
}

int main() 
{
    testVectorInsertsmall();
    testListInsertsmall();
    return 0;
}

//当少量元素随机插入时，二者的耗时几乎相同，但向量仍会稍微快一点