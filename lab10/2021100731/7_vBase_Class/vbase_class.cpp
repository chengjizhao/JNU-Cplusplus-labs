#include <iostream>

using namespace std;

class TOP
{
public:
    int topParam;
};

class MIDDLE1: virtual public TOP
{
public:
    int mid1Param;
};

class MIDDLE2: virtual public TOP
{
public:
    int mid2Param;
};

class BOTTOM: public MIDDLE1, public MIDDLE2
{
public:
    int botParam;
};


int main()
{
    BOTTOM dummy1;
    int* pClass  = reinterpret_cast<int*>(&dummy1);
    int* pParam1 = &dummy1.MIDDLE1::topParam;
    int* pParam2 = &dummy1.MIDDLE2::topParam;
    int* pParam3 = &dummy1.botParam;

    cout << "This is ClassAddr          : " << pClass << endl;
    cout << "This is Param_Mid-Top1_Addr: " << pParam1 << endl;
    cout << "This is Param_Mid-Top2_Addr: " << pParam2 << endl;
    cout << "This is Param_Bot_Addr     : " << pParam3 << endl;

    return 0;
}
