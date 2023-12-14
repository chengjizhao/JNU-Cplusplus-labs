#include <iostream>  
#include <vector>  
#include <thread>  
#include <mutex>   
#include <cmath>  

using namespace std;

#define ThreadCnt 4

// 检查一个数是否为素数  
bool isPrime(int num) 
{  
    if (num < 2) return false;  
    for (int i = 2; i <= sqrt(num); ++i)
    {  
        if (num % i == 0) return false;  
    }  
    return true;  
}

//线程要执行的任务
void findPrimeinScale(int low_, int high_, vector<int>* save_, mutex* lock_)
{
    for(int i=low_; i<=high_; i++)
    {
        if(isPrime(i))
        {
            lock_guard<mutex> lockGuard(*lock_);
            save_->push_back(i);
        }
    }
}


int main()
{
    int minNum, maxNum;
    int rangePerThread;
    vector<int> PrimeSave;
    mutex mlock;

    //输入上下界
    cout << "Please enter the MinLimit and MaxLimit:" << endl; 
    cin >> minNum >> maxNum;
    rangePerThread = ( maxNum - minNum + 1 ) / ThreadCnt;

    //创建线程
    thread processer[ThreadCnt];
    for(int i=0; i<ThreadCnt; i++)
    {
        int begin   = minNum + rangePerThread * i;
        int end     = begin + rangePerThread - 1;
        processer[i] = thread(findPrimeinScale, begin, end, &PrimeSave, &mlock);
    }

    for(int i=0; i<ThreadCnt; i++)
    {
        processer[i].join();
    }

    for(int i=0; i<PrimeSave.size(); i++)
    {
        if(PrimeSave[i] <= maxNum)
        cout << PrimeSave[i] << " ";
    }
    return 0;
}

