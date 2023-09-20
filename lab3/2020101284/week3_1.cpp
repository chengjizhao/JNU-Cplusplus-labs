#include <iostream>
#include <vector>
#include <list>
#include <chrono>

using namespace std;

int main() {
    const int numElements = 100; // 要插入的元素数量

    // 使用 vector 进行插入性能测试
    {
        vector<int> myVector;
        auto start = chrono::high_resolution_clock::now();

        for (int i = 0; i < numElements; i++) {
            int randomNumber = rand();
            myVector.insert(myVector.begin() + randomNumber % (myVector.size() + 1), randomNumber);
        }

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;

        cout << "Vector 插入 " << numElements << " 个元素所用时间: " << duration.count() << " 秒\n";
    }

    // 使用 list 进行插入性能测试
    {
        list<int> myList;
        auto start = chrono::high_resolution_clock::now();

        for (int i = 0; i < numElements; i++) {
            int randomNumber = rand();
            myList.insert(next(myList.begin(), randomNumber % (myList.size() + 1)), randomNumber);
        }

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;

        cout << "List 插入 " << numElements << " 个元素所用时间: " << duration.count() << " 秒\n";
    }

    return 0;
}