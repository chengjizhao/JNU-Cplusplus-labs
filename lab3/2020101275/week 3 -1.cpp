#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>

using namespace std;  // 使用标准命名空间

const int NUM_ELEMENTS = 1000000;  // 要插入的元素数量

int main() {
    vector<int> myVector;
    list<int> myList;

    // 使用当前时间作为随机数种子
    srand(static_cast<unsigned int>(time(nullptr)));

    // 向vector插入元素并测量时间
    clock_t start_time = clock();
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        int random_value = rand();
        myVector.insert(myVector.begin() + (rand() % (myVector.size() + 1)), random_value);
    }
    clock_t end_time = clock();
    double vector_insert_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    // 向list插入元素并测量时间
    start_time = clock();
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        int random_value = rand();
        myList.insert(next(myList.begin(), rand() % (myList.size() + 1)), random_value);
    }
    end_time = clock();
    double list_insert_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "向vector插入"<< NUM_ELEMENTS << " 个元素所需时间: " << vector_insert_time << " 秒\n";
    cout << "向list插入 " << NUM_ELEMENTS << " 个元素所需时间: " << list_insert_time << " 秒\n";

    return 0;
}
//vector的效率高于list
//由于vector是单向数组，list是双向数组，存储空间不连续，通过指针可以高效进行随机访问，但不能随机读取，因此插入元素效率没有vector高。