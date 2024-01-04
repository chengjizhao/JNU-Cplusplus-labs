#include "person.h"
#include <iostream>
using namespace std;

int main() 
{
	person p1;
	person p2("C", 2020103132,20020409,"F",185,75);
	cout << "name: " << p2.name << endl;
    cout << "id: " << p2.getId() << endl;
	cout << "birthday: " << p2.getBirthday()<< endl;
    cout <<"gender:"<<p2.getGender()<<endl;
	cout << "height: " << p2.getHeight() << "cm" << endl;
	cout << "weight: " << p2.getWeight() << "kg" << endl;
	
	cout << endl;
	
	cout <<"size of p2:"<< sizeof(p2) << endl;

	return 0;
}

