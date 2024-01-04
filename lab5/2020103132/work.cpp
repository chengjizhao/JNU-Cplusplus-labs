/*头文件和实现文件分开，实现一个类 person， 他有名字，身份证号， 出生年月日，性别，身高，
体重，这些数据只有名字是public的； 可以通过查询和设置函数，查询设置所有这些属性；
类具有多种构造函数。在主程序里面用不同的初始化方法实现创建多个person对象，打印每个对象占用的
存储空间是多大？并解释为什么对象的尺寸是这么大？
*/
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

