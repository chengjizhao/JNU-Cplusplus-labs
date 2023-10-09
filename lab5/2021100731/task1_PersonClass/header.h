#ifndef __HEADER_H
#define __HEADER_H

#include <string>

using namespace std;


class cPerson
{
public:
    string name;
    void data_write(int n);
    void data_read(void);
    void test(void);

    cPerson():  nBirthyear(0),nBirthmonth(0),nBirthday(0),
                nGender(3),nHeight(0),nWeight(0){}
private:
    int nBirthyear;
    int nBirthmonth;
    int nBirthday;
    int nGender;
    int nHeight;
    int nWeight;
};

/*----------------------------------------------------*/
class Test
{
private:
    char v;
    int m;
    int a;
    //string x;
public:
    int b;
    Test();
    Test(int m);
    void display();
};




#endif
