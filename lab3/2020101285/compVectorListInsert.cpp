#include<iostream>
#include <random>
#include <ctime> 
#include<vector>
#include<list>
#include<iterator>
#include<sys/time.h>

#define INSERTNUM 10000
#define SIZE 10000

using namespace std;

int getrand(int min,int max);

int main()
{
    float timeuse_v,timeuse_l;
    vector<int>vet(SIZE);
    list<int>lst(SIZE);
    vector<int>::iterator it_v;
    list<int>::iterator it_l;
    int insertpos[INSERTNUM];
    struct timeval start,end;
    

    //为了两容器插入时的位置一样，便于比较，提前生成随机数组存储起来
    for (int i = 0; i < INSERTNUM; i++) {
        insertpos[i]=getrand(0,SIZE-1+i);//每插入一个，容器size变大，随机数生成范围也变大
        //cout<<"随机数: "<<insertpos[i]<<endl;
    }

    gettimeofday(&start , NULL);
    for (int i = 0; i < INSERTNUM; i++) {
        it_v=vet.begin();
        advance(it_v,insertpos[i]);
        vet.insert(it_v,i+1);
    }
    gettimeofday(&end , NULL );
    timeuse_v = 1000000 * (end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec;

    gettimeofday(&start , NULL);
    for (int i = 0; i < INSERTNUM; i++) {
        it_l=lst.begin();
        advance(it_l,insertpos[i]);
        lst.insert(it_l,i+1);
    }
    gettimeofday(&end , NULL );
    timeuse_l = 1000000 * (end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec;

    cout<<"time for list insert:"<<timeuse_l<<endl<<"time for vector insert:"<<timeuse_v<<endl;
    return 0;
}

int getrand(int min,int max)
{
    default_random_engine e;
    e.seed(time(0)
    );
    return (e()%(max-min+1)+min);
}

