#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> list1;
    list<int> list2;

    // 向 list1 中插入元素
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    // 向 list2 中插入元素
    list2.push_back(4);
    list2.push_back(5);
    list2.push_back(6);

    // 对比两个列表的元素
    if (list1 == list2) {
        cout << "两个列表相等" << endl;
    }
    else {
        cout << "两个列表不相等" << endl;
    }

    return 0;
}