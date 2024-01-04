#include<iostream>
#include"head.h"

    void Person::show()
    {
        cout << "name : " << name << endl ;
        cout << "ID : " << ID << endl ;
        cout << "birthday : " << birthday << endl;
        cout << "tall : " << tall << endl ;
        cout << "heavy : " << heavy << endl ;
    }


    Person::Person(string a , int b , string c , int d ,int e)
    {
        name=a;
        ID=b;
        birthday=c;
        tall=d;
        heavy=e;
    }