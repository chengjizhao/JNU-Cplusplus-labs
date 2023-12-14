#include <iostream>
#include <memory>
#include "library.h"

using namespace std;

Library lib1;

int main()
{
    int flag = 1;
    //往library中载入两本书
    lib1.Add_Book("To Kill A Moking Bird", "HarperLee");
    lib1.Add_Book("Journey To the West", "Wu Chen'en");
    //展示所有书
    lib1.Show_Book();
    //删除第2本书
    lib1.Delete_Book(2);
    //展示所有书
    lib1.Show_Book();
    while(flag)
    {
        cout << "Press 0 to quit." << endl;
        cin >> flag;
    }
    

    return 0;
}
