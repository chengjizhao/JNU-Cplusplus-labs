#include "person.h"
#include <iostream>

using namespace std;

int main() {
    Person p1;
    Person p2("Alice");
    Person p3("Bob", "123456789");
    Person p4("Charlie", "0123456789", "2002-01-01", 'M', 180, 78);

    // 打印对象的存储空间大小
    cout << "Size of p1: " << sizeof(p1) << " bytes" << endl;
    cout << "Size of p2: " << sizeof(p2) << " bytes" << endl;
    cout << "Size of p3: " << sizeof(p3) << " bytes" << endl;
    cout << "Size of p4: " << sizeof(p4) << " bytes" << endl;

    return 0;
}
