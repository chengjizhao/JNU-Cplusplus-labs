/*2. 创建两个线程，一个线程生成并输出随机数，
另一个线程计算生成的随机数的平方根。
使用条件变量确保计算线程在生成线程完成后再开始执行。
输出最终的随机数和其平方根，并保存在共享的数据结构中。*/

#include <iostream>  
#include <thread>  
#include <vector>  
#include <mutex>  
#include <condition_variable>  
#include <random>  
#include <functional>  

  
std::random_device rd;  
std::mt19937 gen(rd());  
std::uniform_real_distribution<>dis(0, 1);  
  
std::mutex mtx;  
std::condition_variable cv;  
bool ready = false;  

  
void generate_random_number(std::vector<double>& data) 
{  
    std::lock_guard<std::mutex> lock(mtx);  
    while (!ready) cv.wait(lock);  
    data.push_back(dis(gen));  
}  
  
void calculate_square_root(std::vector<double>& data) 
{  
    std::lock_guard<std::mutex> lock(mtx);  
    if (!data.empty()) 
    {  
        double number = data.back();  
        data.pop_back();  
        double square_root = std::sqrt(number);  
        std::cout<<"Random number:"<<number<<",Square root:"<<square_root<<std::endl;  
    }  
}  
  
int main() 
{  
    std::vector<double> data;  
    std::thread t1(generate_random_number, std::ref(data));  
    std::thread t2(calculate_square_root, std::ref(data));  
    t1.join();  
    t2.join();  
    return 0;  
}