#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

bool prime(int num){
    if(num<2){
        return false;
    }
    for(int i=2;1<=num/i;++i){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

void store(int start,int end,vector<int>& result,mutex& mtx){
    for(int i=start;i<end;++i){
        if(prime(i)){
            lock_guard<mutex> lock(mtx);
            result.push_back(i);
        }
    }
}

int main(){
    int start=1;
    int end=100;
    vector<int> prime_numbers;
    mutex mtx1;
    thread thread1(prime, start, end/2, ref(prime_numbers), ref(mtx1)); 
    thread thread2(prime, end/2, end, ref(prime_numbers), ref(mtx1));
    thread1.join();
    thread2.join();
    cout << "1-100内所有素数: ";
    for (int prime : prime_numbers) {
        cout << prime << " ";
    }
    cout <<endl;
    return 0;
}