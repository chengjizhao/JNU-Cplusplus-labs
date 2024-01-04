#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;
mutex mtx;
int c=0;  // 共享计数器
void increment(){
    for (int i=0;i<100;++i) {
        lock_guard<mutex> lock(mtx);
        ++c;
        cout<< "共享计数器"<<c<<endl;
    }
}
void decrement() {
    for (int i = 0; i < 50; ++i) {
        lock_guard<mutex> lock(mtx);
        --c;
        cout << "递减计数器"<<c<<endl;
    }
}
 
int main() {
    thread t1(increment);
    thread t2(decrement);
    t1.join();
    t2.join();
    std::cout<<"最终值为"<<c<<endl;  // 输出最终的计数器值
    return 0;
}