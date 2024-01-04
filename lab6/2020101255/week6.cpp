#include <iostream>

using namespace std;

class TEST
{
    private:
    static void Print1(){cout << "private print" << endl;}

    public:
    static void Print2(){Print1();}
};

int main()
{
    TEST t1;
    void (*ptr)();
    ptr = t1.Print2;
    ptr();

    return 0;
}