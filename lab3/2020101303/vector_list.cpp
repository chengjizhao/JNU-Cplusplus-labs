#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<sys/time.h>
using namespace std;
const int count = 10000;
int c_random(int min,int max) {
    int R = (rand() % (max - min +1)) + min;
    return R;
}
void vector_insert(vector<int>& Vector, int number) {
    if (number == 0) {
        return;
    }
    int randomNumber = c_random(0,100);
    int randomPlace = c_random(0, Vector.size());
    Vector.insert(Vector.begin() + randomPlace ,randomNumber);
    vector_insert(Vector, number - 1);
}
void list_insert(list<int>& List, int number) {
    if (number == 0) {
        return;
    }
    int randomNumber = c_random(0,100);
    int randomPlace = c_random(0, List.size());
    auto it = List.begin();
    advance(it ,randomPlace);
    List.insert(it ,randomNumber);
    list_insert(List, number - 1);
}
int main() 
{
    vector<int> Vector;
    list<int> List;
    for (int i=1; i<= count; i++)
    {
        Vector.push_back(i);
        List.push_back(i);
    }
    struct timeval start_vector, end_vector;
    gettimeofday(&start_vector, NULL);
    vector_insert(Vector, count);
    gettimeofday(&end_vector, NULL);
    int timeuse_vector =1000000 * (end_vector.tv_sec - start_vector.tv_sec) + end_vector.tv_usec - start_vector.tv_usec;
    struct timeval start_list, end_list;
    gettimeofday(&start_list, NULL);
    list_insert(List, count);
    gettimeofday(&end_list, NULL);
    int timeuse_list =1000000 * (end_list.tv_sec - start_list.tv_sec) + end_list.tv_usec - start_list.tv_usec;
    cout << "在vector容器中随机插入" << count << "个随机元素所用时间：" << timeuse_vector << " us" << endl;
    cout << "在list容器中随机插入" << count << "个随机元素所用时间：" << timeuse_list << " us" << endl;
    return 0;
}
