#include "person.h"
#include <iostream>
using namespace std;
int main()
{
	Person per1;
	Person per2();
	string name,id,birthyear,birthmonth,birthday;
	double weight,height;
	cout<<"请输入姓名：";
	cin>>name;
	cout<<"请输入身份证：";
	cin>>id;
	cout<<"请输入出生年：";
	cin>>birthyear; 
	cout<<"请输入出生月："; 
	cin>>birthmonth;
	cout<<"请输入出生日："; 
	cin>>birthday;
	cout<<"请输入体重（kg）："; 
	cin>>weight; 
	cout<<"请输入身高（cm）：";
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
	cout << "姓名：" << per2.getName()<< endl;
    cout << "身份证：" << per2.getId() << endl;
    cout << "出生年：" << per2.getBirthyear() << endl;
    cout << "出生月：" << per2.getBirthmonth() << endl;
    cout << "出生日：" << per2.getBirthday()<< endl;
    cout << "身高：" << per2.getHeight() << endl;
    cout << "体重：" << per2.getWeight() << endl;

	return 0;
}
