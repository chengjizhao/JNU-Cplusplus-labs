#include<iostream>
using namespace std;
class TEXT
{
    private:
    static void Print1(){cout << "private print" << endl;}

    public:
    static void Print2(){Print1();}
};

int main()
{
    TEXT t1;
    void (*ptr)();
    ptr = t1.Print2;
    ptr();

    return 0;
}