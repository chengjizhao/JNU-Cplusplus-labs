#include "person.h"
#include <iostream>
using namespace std;
int main()
{
	Person per1;
	Person per2();
	string name,id,birthyear,birthmonth,birthday;
	double weight,height;
	cout<<"������������";
	cin>>name;
	cout<<"���������֤��";
	cin>>id;
	cout<<"����������꣺";
	cin>>birthyear; 
	cout<<"����������£�"; 
	cin>>birthmonth;
	cout<<"����������գ�"; 
	cin>>birthday;
	cout<<"���������أ�kg����"; 
	cin>>weight; 
	cout<<"��������ߣ�cm����";
	cin>>height; 
	per2.setName(name);
	per2.setId(id);
	per2.setBirthyear(birthyear);
	per2.setBirthmonth(birthmonth);
	per2.setBirthday(birthday);
	per2.setHeight(height);
	per2.setWeight(weight);
	cout<<sizeof(per1)<<;
	cout<<sizeof(per2)<<;
	cout << "������" << per2.getName()<< endl;
    cout << "���֤��" << per2.getId() << endl;
    cout << "�����꣺" << per2.getBirthyear() << endl;
    cout << "�����£�" << per2.getBirthmonth() << endl;
    cout << "�����գ�" << per2.getBirthday()<< endl;
    cout << "��ߣ�" << per2.getHeight() << endl;
    cout << "���أ�" << per2.getWeight() << endl;

	return 0;
}
