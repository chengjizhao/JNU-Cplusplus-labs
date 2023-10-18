#include <iostream>

using namespace std;

class TEST
{
private:
    static void Print1() 
    { 
        cout << "private print" << endl;
    }

public:
    static void Print2()
    { 
        Print1(); 
    }
}test;

int main()
{
    void (*ptr)();
    ptr = test.Print2;
    ptr();

    return 0;
}