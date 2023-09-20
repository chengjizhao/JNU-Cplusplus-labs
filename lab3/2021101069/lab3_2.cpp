#include <iostream>  
#include <vector>  
#include <list>  
#include <chrono> 
#include <cmath>
  
using namespace std;  
  
int main() {  
    // 设置容器大小  
    const int size = 10000;  
  
    // 创建两个容器  
    vector<int> vec;  
    list<int> lst;  
  
    // 填充容器  
    for (int i = 0; i < size; ++i) {  
        vec.push_back(i);  
        lst.push_back(i);  
    }  
  
    // 对vector进行随机插入  
    auto start = chrono::high_resolution_clock::now();  
    for (int i = 0; i < size; ++i) {  
        vec.insert(vec.begin() + rand() % (i + 1), i);  
    }  
    auto end = chrono::high_resolution_clock::now();  
    auto duration_vec = chrono::duration_cast<chrono::milliseconds>(end - start);  
    cout << "Time taken for random insertion in vector: " << duration_vec.count() << " ms" << endl;  
  
    // 对list进行随机插入  
    start = chrono::high_resolution_clock::now();  
    for (int i = 0; i < size; ++i) {  
        lst.insert(lst.begin() + rand() % (i + 1), i);  
    }  
    end = chrono::high_resolution_clock::now();  
    auto duration_lst = chrono::duration_cast<chrono::milliseconds>(end - start);  
    cout << "Time taken for random insertion in list: " << duration_lst.count() << " ms" << endl;  
  
    return 0;  
}