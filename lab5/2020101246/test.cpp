#include<iostream>
#include"person.h"
using namespace std;
#include <iostream>
#include "person.h"

int main() {
    int n;
    Self p1;  // 默认构造函数，不传递任何参数
    std::cout << "Size of person1: " << sizeof(Self) << " bytes" << std::endl;

    Self p2("wang", "777777", "2000-01-01", "female", 160, 50);  // 使用所有参数的构造函数
    std::cout << "Size of person2: " << sizeof(Self) << " bytes" << std::endl;
    p2.People();
        cout<<"Enter your choice: 1:id 2:brithday 3:sexual 4:height 5:weight 6:out \n";
        cin>>n;
    p2.Exchange(n);
    return 0;
}