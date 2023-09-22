//写一个程序比较vector 和 list 两种容器对元素随机插入支持的优劣。
#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main()
{
    //vector随机插入
    vector<int>shili{};
    clock_t start_time=clock();
    for(int i=0;i<10000;i++)
    {
        shili.push_back(i);
    }
    clock_t end_time=clock();
    printf("using time:%f\n",((end_time - start_time)/CLOCKS_PER_SEC));

    //list随机插入
    list<int>shi;
	clock_t start_time1=clock();
    for(int n=0;n<5000;n++)
    {
        shi.push_back(n);
    }
    clock_t end_time1=clock();
    cout<<"using time:"<<end_time1 - start_time1<< "ms" << endl;
    

    return 0;
}


    

