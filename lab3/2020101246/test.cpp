// 写一个程序比较向量和列表两个容器对元素随机插入支持的优劣。 
//2 如果把任意一个正整数n分割成单个数字，比如23，拆成2，3个两个数字，
//然后全部平方并相加，得到一个新数m，本例中m = 2×2 + 3×3=13 
//如果这个数字m=1，现在是忧伤的，否则，继续进行分割，
//然后求平方和。本例中就是把13分割继续为：1×1+3×3=10，1×1+0×0=1，
//最终23经过三次这样的损伤，损失了1，因此23是一个忧伤的数，
//任务：用程序实现把1000以内的幸福的数和忧虑的数都算出来了。
//3总结：STL标准容器的特点和典型
 
#include<iostream> ;
#include <vector>  ;
#include <list> ;
#include <chrono>;  
using namespace std;   
int main() {  
    // 容器大小  
    const int container_size = 10000;  
    // 随机插入位置数组  

    vector<int> insert_positions;  

    for (int i = 0; i < container_size; ++i) {  

        insert_positions.push_back(rand() % container_size);  
    }  
    // 向量容器  
    vector<int> vec(container_size);  
    auto start = chrono::high_resolution_clock::now();  
    for (int i = 0; i < container_size; ++i) {  

        vec.insert(vec.begin() + insert_positions[i], i);  

    }  

    auto end = chrono::high_resolution_clock::now();  
    chrono::duration<double> vec_insert_time = end - start;  
    // 列表容器  
    list<int> lst(container_size);  
    start = chrono::high_resolution_clock::now();  
    for (int i = 0; i < container_size; ++i) {  
        lst.insert(lst.begin() + insert_positions[i], i);  
    }  
    end = chrono::high_resolution_clock::now();  
    chrono::duration<double> lst_insert_time = end - start;  
   // 输出结果  
    cout << "Vector insert time: " << vec_insert_time.count() << " seconds" << endl;  
    cout << "List insert time: " << lst_insert_time.count() << " seconds" << endl;  
    return 0;  
}