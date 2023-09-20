#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<iterator>
using namespace std;

void outline(int n)
{
    cout << n << " " ;
}

int main()
{
    list<int> b={1,2,3,4,5};
    list<int> d;
    vector<int> a={1,2,3,4,5};
    vector<int>:: iterator a1=a.begin()+3;
    int c;
    cout << "vector的内容为: " ;
    for_each(a.begin(),a.end(),outline);
    cout << endl ;
    cout << "请在3和4之间输入一个数" << endl ;
    cin >> c;
    a.insert(a1,c);
    cout << "此时vector的内容为: " ;
    for_each(a.begin(),a.end(),outline);
    cout << endl ;
    for(int i=0;i<a.size();i++)
    {
        d.push_back(a[i]);
    }
    cout << "复制vector的内容到一个list1中" << endl << "此时list1为: ";
    for_each(d.begin(),d.end(),outline);
    cout << endl ;
    cout << "此时list2为:" ;
    for_each(b.begin(),b.end(),outline);
    cout << endl ;
    b.splice(b.begin(),d);
    cout << "把list1插入到list2前面,此时list2为: " ;
    for_each(b.begin(),b.end(),outline);
    cout << endl ;
    b.sort();
    b.unique();
    cout << "把list2排序后合并相同项,此时list2为: ";
    for_each(b.begin(),b.end(),outline);
    cout << endl ;
    d.sort();
    b.merge(d);
    cout << "把list1合并list2,此时list1为: ";
    for_each(d.begin(),d.end(),outline);
    cout << endl ;
    cout << "此时list2为: ";
    for_each(b.begin(),b.end(),outline);
    cout << endl ;
    return 0;
}