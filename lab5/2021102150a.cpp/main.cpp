#include<iostream>
#include "person.h"
using namespace std;

main(){
    Cperson p;
    Cperson();
    cout<<"请输入姓名："<<endl;
    cin>>p.name;
    cout<<endl;
    while(1){
        cout<<"想执行什么操作：1.修改数据 2.查询数据 3.结束操作"<<endl<<"请输入：";
        int n,x=0;
        cin>>n;
        cout<<endl;
        switch (n)
        {
        case 1:
            p.setDate();
            break;
        case 2:
            p.showDate();
            break;
        case 3:
            x=1;
            break;
        default:
            cout<<"错误，请重新输入："<<endl;
            break;
        }
        cout<<endl;
        if(x)break;
    }
    cout<<"类的大小为：";
    p.size();
    //string的大小为32，int的大小为4，double的大小为8，最终结果为96
    return 0;
}