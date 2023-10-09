#include "header.h"
#include <iostream>

using namespace std;

void cPerson::data_write(int n)
{
    switch (n)
    {
    case 0:
        break;
    case 1: //写入生日
        cout << "输入生日年月日(空格隔开)" << endl;
        cin >> nBirthyear >> nBirthmonth >> nBirthday;
        break;
    case 2: //写入性别
        cout << "输入性别(0:女性 1:男性)" << endl;
        cin >> nGender;
        break;
    case 3:
        cout << "输入身高" << endl;
        cin >> nHeight;
        break;
    case 4:
        cout << "输入体重" << endl;
        cin >> nWeight;
        break;
    default:
        break;
    }
}

void cPerson::data_read(void)
{
    cout << "姓名: " << name << endl;
    cout << "生日: " << nBirthyear << "/" << nBirthmonth << "/" << nBirthday << endl;
    if(nGender == 0){cout << "性别: 女" << endl;}
    else if(nGender == 1){cout << "性别: 男" << endl;}
    else{cout << "性别: 未输入" << endl;}
    cout << "身高: " << nHeight << endl;
    cout << "体重: " << nWeight << endl;
}

void test(void)
{
    //
}

/*-------------------------------------------*/
Test::Test()
{
    this->m = 0;
}

Test::Test(int m)
{
    this->m = m;
}

void Test::display()
{
    cout << "The value of m is: " << this->m << endl;
}
