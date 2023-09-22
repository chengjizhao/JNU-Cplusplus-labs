#include <iostream>
#include <vector>
#include <list>
#include <chrono>

using namespace std;

int main() {
    const int numElements = 100; // Ҫ�����Ԫ������

    // ʹ�� vector ���в������ܲ���
    {
        vector<int> myVector;
        auto start = chrono::high_resolution_clock::now();

        for (int i = 0; i < numElements; i++) {
            int randomNumber = rand();
            myVector.insert(myVector.begin() + randomNumber % (myVector.size() + 1), randomNumber);
        }

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;

        cout << "Vector ���� " << numElements << " ��Ԫ������ʱ��: " << duration.count() << " ��\n";
    }

    // ʹ�� list ���в������ܲ���
    {
        list<int> myList;
        auto start = chrono::high_resolution_clock::now();

        for (int i = 0; i < numElements; i++) {
            int randomNumber = rand();
            myList.insert(next(myList.begin(), randomNumber % (myList.size() + 1)), randomNumber);
        }

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;

        cout << "List ���� " << numElements << " ��Ԫ������ʱ��: " << duration.count() << " ��\n";
    }

    return 0;
}