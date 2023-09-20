#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    const int member = 10000;
    vector<int> vectorcontain ;
    list<int> listcontain;

    srand(static_cast<unsigned int>(time(nullptr)));

    clock_t start_time = clock();
    for (int i = 0; i < member; ++i) {
        int random_value = rand();
        vectorcontain.insert(vectorcontain.begin() + (rand() % (vectorcontain.size() + 1)), random_value);
    }
    clock_t end_time = clock();
    double vector_insert_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "vector插入"<< member << "个成员所需时间:" << vector_insert_time << "秒\n";

    start_time = clock();
    for (int i = 0; i < member; ++i) {
        int random_value = rand();
        listcontain.insert(next(listcontain.begin(), rand() % (listcontain.size() + 1)), random_value);
    }
    end_time = clock();
    double list_insert_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "list插入" << member << "个成员所需时间:" << list_insert_time << "秒\n";

    return 0;
}