#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> list1;
    list<int> list2;

    // �� list1 �в���Ԫ��
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    // �� list2 �в���Ԫ��
    list2.push_back(4);
    list2.push_back(5);
    list2.push_back(6);

    // �Ա������б��Ԫ��
    if (list1 == list2) {
        cout << "�����б����" << endl;
    }
    else {
        cout << "�����б����" << endl;
    }

    return 0;
}