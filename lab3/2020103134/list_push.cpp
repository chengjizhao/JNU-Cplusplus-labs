#include<iostream>
#include<list>

using namespace std;

int main()
{
    list<int> l;
    int num=1000;
    for(int i=0;i<num;i++)
    {
        l.push_back(i);
    }
    system("pause");
    return 0;

}