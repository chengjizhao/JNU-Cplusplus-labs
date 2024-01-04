#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class Counter
{
private:
    mutex mutex_;
public:
    int count = 100;

    void PLUS()
    {
        unique_lock<mutex> lock(mutex_);
        count++;
        cout << "Counter is PLUS!" << "Now " << count << " left." << endl;
    }

    void MINUS()
    {
        unique_lock<mutex> lock(mutex_);
        count--;
        cout << "Counter is MINUS!" << "Now " << count << " left." << endl;
    }
};

/*加法任务*/
void Counter_PLUS(Counter* coun)
{
    for(int i=0; i<100; i++)
    {
        coun->PLUS();
    }
}
/*减法任务*/
void Counter_MINUS(Counter* coun)
{
    for(int i=0; i<50; i++)
    {
        coun->MINUS();
    }
}


int main()
{
    Counter counter1;

    thread counterPLUS(Counter_PLUS, &counter1);
    thread counterMINUS(Counter_MINUS, &counter1);

    counterPLUS.join();
    counterMINUS.join();

    return 0;
}