#include <iostream>
#include <vector>
#include <list>
#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>

using namespace std;
int main() {
    vector<int> vec;
    list<int> lst;
    struct timeval start,end;
    
    // 测试vector的随机插入性能
    gettimeofday(&start,NULL);
    for (int i = 0; i < 100000; ++i) {
        vec.insert(vec.begin() + i/2, i);
    }
    sleep(1);
    gettimeofday(&end,NULL);
    int timeuse = 1000000 * (end .tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("time: %d us\n", timeuse);

    // 测试list的随机插入性能
    gettimeofday(&start,NULL);
    for (int i = 0; i < 100000; ++i) {
        lst.insert(lst.begin(), i);
    }
    sleep(1);
    gettimeofday(&end,NULL);
    timeuse = 1000000 * (end .tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("time: %d us\n", timeuse);

    return 0;
}
