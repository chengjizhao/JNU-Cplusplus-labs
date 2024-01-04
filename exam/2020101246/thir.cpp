//使用C++标准库创建一个简单的线程池，其中包含多个工作线程。  
//实现一个任务队列，线程池中的线程从队列中取出任务执行。 
// 创建多个任务，并将它们提交给线程池执行。  输出任务执行的结果。

#include<iostream>
#include<mutex>
#include<thread>
#include<vector>

const int NUM_MIssion = 4;
std::vector<std::mutex>objth(NUM_MIssion);
std::mutex outMutex;
void mission(int num)
{
    while(true)
    {
        std::cout<<"mission "<<num<<" is start"<<std::endl;
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        std::lock_guard<std::mutex>outlock(outMutex);//protect cout
        std::cout<<"mission "<<num<<" is done ."<<std::endl;

    }

}

int main()
{
    std::vector<std::thread>MIssion;

    for(int i=0;i<NUM_MIssion;i++)
    {
        MIssion.emplace_back(mission,i);
    }
    for(auto& mission_thread : MIssion)
    {
        mission_thread.join();
    }
    return 0;
}