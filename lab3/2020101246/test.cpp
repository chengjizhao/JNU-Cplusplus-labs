#include <iostream>  
#include <vector>  
#include <list>  
#include <chrono>  
#include <random>  
int main() {  
    // 设定随机种子  
    std::default_random_engine generator(time(nullptr));  

    std::uniform_int_distribution<int> distribution(0, 99);  
    // 创建向量和列表  

    std::vector<int> vec;  

    std::list<int> lst;  
    // 向量和列表的大小  

    const int size = 10000;  
    // 向量和列表的插入时间  

    auto vec_insert_time = std::chrono::high_resolution_clock::now();  

    auto lst_insert_time = std::chrono::high_resolution_clock::now();  
    // 向向量和列表中插入随机元素  

    for (int i = 0; i < size; ++i) {  

        vec.insert(vec.begin(), distribution(generator));  

        lst.insert(lst.begin(), distribution(generator));  

    }  
    // 计算插入时间  

    auto vec_insert_duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - vec_insert_time);  
    auto lst_insert_duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - lst_insert_time);  
    // 输出结果  

    std::cout << "Vector insert time: " << vec_insert_duration.count() << " ms" << std::endl;  
    std::cout << "List insert time: " << lst_insert_duration.count() << " ms" << std::endl;  
    return 0;  

}