#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring> 
#include <map> 
#include <list>
#include <ctime>
#include <cstdlib>

using namespace std;

//随机插入10000个数字
vector<int> vec;
list<int>   lis;

clock_t nstart,nend;


int getRand(int min, int max);
int size = 0;


int main()
{
    cout << "将随机插入10000个数字" << endl;
    double ntime = 0;

    //vector随机插入
    auto pvec = vec.begin();
    nstart = clock();
    
    for (int i=0; i < 9999; i++)
    {
        advance(pvec, getRand(0, size));
        vec.insert(pvec,1);
        size++;
        pvec = vec.begin();
    }
    nend = clock();
    ntime = nend - nstart;

    cout << "time consumption of Vector: " << ntime <<endl;

    size = 0;
    /********************************************************/
    //list随机插入
    auto plis = lis.begin();
    nstart = clock();

    for (int i=0; i < 9999; i++)
    {
        advance(plis, getRand(0, size));
        lis.insert(plis,1);
        size++;
        plis = lis.begin();
    }
    nend = clock();
    ntime = nend - nstart;

    cout << "time consumption of List: " << ntime <<endl;

    return 0;
}


int getRand(int min, int max) {
    return ( rand() % (max - min + 1) ) + min ;
}

/*实验发现，随机写入时list类型对时间的消耗较vector类型更多*/