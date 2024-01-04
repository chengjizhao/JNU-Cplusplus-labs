#include <iostream>
using namespace std;

#include <thread>
#include <mutex>

mutex mtx;
int counter = 0;

void inCounter()//加法
{
    for (int i = 0; i < 100; i++) {
        lock_guard<mutex> lock(mtx);
        ++counter;
    }
}

void deCounter() //减法
{
    for (int i = 0; i < 50; i++) {
        lock_guard<mutex> lock(mtx); 
        --counter;
    }
}

int main() {
    thread t1(inCounter);
    thread t2(deCounter);

    t1.join();
    t2.join();

    cout << "Final counter value: " << counter << endl;
    system("pause");
    return 0;
}
