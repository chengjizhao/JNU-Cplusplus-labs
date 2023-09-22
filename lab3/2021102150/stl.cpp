#include<iostream>
#include<vector>
#include<list>
#include<stdlib.h>//随机数函数
#include<algorithm>//find函数
#include <chrono>  // 用于计时
#include <ctime>  // 用于获取当前时间

using namespace std;

vector<int> v(10010);
list<int> l;

void li(){
    int a=rand()%10000;
    list<int>::iterator b[10010];
    for(int i=0;i<=10000;i++){
        b[i] = find(l.begin(),l.end(),a);
    }
    std::chrono::time_point<std::chrono::system_clock> start, end; // 定义时间点
    start = std::chrono::system_clock::now(); // 获取当前时间点
    // 要测试的程序
    
    for(int i=0;i<=10000;i++){
        int c=rand()%10000;
        l.insert(b[i],c);
    }

    end = std::chrono::system_clock::now();  // 获取程序结束时间点
    // 计算程序执行时间
    std::chrono::duration<double, std::milli> elapsed_time = end - start;
    std::cout << "list容器随机插入，程序执行时间： " << elapsed_time.count() << " 毫秒" << std::endl;
}

void ve(){
    std::chrono::time_point<std::chrono::system_clock> start, end; // 定义时间点
    start = std::chrono::system_clock::now(); // 获取当前时间点
    // 要测试的程序
    
    for(int i=0;i<=10000;i++){
        int a=rand()%10000;
        int b=rand()%10000;
        v.insert(v.begin()+a,b);
    }

    end = std::chrono::system_clock::now();  // 获取程序结束时间点
    // 计算程序执行时间
    std::chrono::duration<double, std::milli> elapsed_time = end - start;
    std::cout << "vector容器随机插入，程序执行时间： " << elapsed_time.count() << " 毫秒" << std::endl;
}

int main(){
    unsigned int seed=123;
    srand(seed);
    li();
    ve();
    return 0;
}