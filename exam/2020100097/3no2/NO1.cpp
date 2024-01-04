#include <iostream>  
#include <thread>  
#include <mutex>  
  
std::mutex mtx; 
int counter = 0;
  
void incrementCounter() {  
    for (int i = 0; i < 100; ++i) {  
        std::lock_guard<std::mutex> lock(mtx);  
        ++counter;  
    }  
}  
  
void decrementCounter() {  
    for (int i = 0; i < 50; ++i) {  
        std::lock_guard<std::mutex> lock(mtx); 
        --counter;  
    }  
}  
  
int main() {  
    std::thread t1(incrementCounter);   
    std::thread t2(decrementCounter); 
  
    t1.join();
    t2.join(); 
  
    std::cout << "最终的计数器值为: " << counter << std::endl;  
  
    return 0;  
}