#include<iostream>
#include<list>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include<iterator> 
using namespace std;
//#define	CLOCKS_PER_SEC	((clock_t)1000)

int main()
{
	clock_t start,finish;
	int i,j=0;
	double Times,times;
	start=clock();
	list<int> mylist;
	list<int>::iterator ite1;
	cout << &ite1;
	ite1=mylist.begin();
	for(i=0;i<10000;i++)
	{
		advance(ite1, rand()%100+1);
		mylist.push_back(j);//插入1
	    ite1=mylist.begin();
		++*ite1;j=j+1;     
	}
	finish=clock();
	cout << "list:" << &ite1 << endl;
	cout << "开始时间打点:" << start << endl;
	cout << "结束时间打点:" << finish << endl;
    Times=(double)(finish-start)/CLOCKS_PER_SEC;
	cout << "运行时间(ms):" << Times << endl;

	vector<int> vec;
	vector<int>::iterator ite2;
	cout << &ite2;
	start=clock();j=0;
	ite2=vec.begin();
	for(i=0;i<10000;i++)
	{
		advance(ite2, rand()%100+1);
		vec.push_back(j);//插入1
	    ite2=vec.begin();
		++*ite2;j=j+1;     
	}
	finish=clock();
	cout << "vector:" << &ite2<< endl;
	cout << "开始时间打点:" << start << endl;
	cout << "结束时间打点:" << finish << endl;
    times=(double)(finish-start)/CLOCKS_PER_SEC;
	cout << "运行时间(ms):" << times << endl;
	return 0;
}