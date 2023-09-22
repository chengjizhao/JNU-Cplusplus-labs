#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    //构建vector list
	vector<int>v(60);
	list<int>l(60);
	size_t size;
	srand(NULL);//随机数种子；
	
	//定义放时间的元素                 
	clock_t start,v_time,l_time; 
	
	//要插入的元素个数
	int num;
	cout<<"输入要插入的元素个数：";
	cin>>num; 
		
	//开始计时1
	size=60;
	start=clock();
	
	//定义迭代器1
	vector<int>::iterator it_v=v.begin();//或 auto it_v = v.begin();
	for(int i=0;i<num;i++) 
	{
		advance(it_v,rand()%(size-1));//迭代器移动随机位数
		v.insert(it_v,0);
		++size;
		it_v=v.begin();
	}
	v_time=clock()-start;//结束计时1，计算时间；]
	
	//开始计时2
	size=60;
	start=clock();	                
	//定义迭代器2
	list<int>::iterator it_l=l.begin();//或 auto it_l=l.begin();
	for(int i=0;i<num;i++) 
	{
		advance(it_l,rand()%(size-1));//迭代器移动随机位数
		l.insert(it_l,0);
		++size;
		it_l=l.begin();
	}
	l_time=clock()-start;//结束计时，计算时间；
	
	cout<<"vector用时为："<<v_time<<"ms"<<endl; 
 	cout<<"list用时为："<<l_time<<"ms"<<endl; 
 	
 	return 0;
 } 
 
 
