#include<iostream>
#include<string>
#include "person.h"
using namespace std;

void Cperson::setDate(){
    while (1)
    {
        cout<<"要设置什么数值？"<<endl;
        cout<<"身份证：1"<<endl<<"出生日期：2"<<endl<<"性别：3"<<endl
        <<"身高：4"<<endl<<"体重：5"<<endl<<"请输入：";
        int n,x=0;
        cin>>n;
        cout<<endl;
        switch (n)
        {
        case 1:
            cout<<"请输入身份证号:"<<endl;
            cin>>IDnumber;
            break;
        case 2:
            cout<<"请输入年份:"<<endl;
            cin>>year;
            cout<<"请输入月份:"<<endl;
            cin>>mounth;
            cout<<"请输入日期:"<<endl;
            cin>>day;
            break;
        case 3:
            cout<<"请输入性别（男1，女2）:"<<endl;
            cin>>sex;
            break;
        case 4:
            cout<<"请输入身高:"<<endl;
            cin>>height;
            break;
        case 5:
            cout<<"请输入体重:"<<endl;
            cin>>weight;
            break;
        default:
            cout<<"错误，请重新输入";
            x=1;
            break;
        }
        if(!x)break;
    }
}

void Cperson::showDate(){
    while (1)
    {
        cout<<"要查看什么数值？"<<endl;
        cout<<"身份证：1"<<endl<<"出生日期：2"<<endl<<"性别：3"<<endl
        <<"身高：4"<<endl<<"体重：5"<<endl<<"全部打印：6"<<endl;
        int n,x=0;
        char a;
        cin>>n;
        cout<<endl;
        switch (n)
        {
        case 1:
            cout<<"身份证号:"<<IDnumber<<endl;
            break;
        case 2:
            cout<<"出生日期"<<year<<"/"<<mounth<<"/"<<day<<endl;
            break;
        case 3:
            cout<<"性别:";
            if(sex==1)cout<<"男"<<endl;
            if(sex==2)cout<<"女"<<endl;
            else cout<<" "<<endl;
            break;
        case 4:
            cout<<"身高:"<<height<<endl;
            break;
        case 5:
            cout<<"体重:"<<weight<<endl;
            break;
        case 6:
            cout<<name<<endl<<"身份证号："<<IDnumber<<endl<<"出生日期:"<<year<<"/"<<mounth<<"/"<<day<<endl<<"性别：";
            if(sex==1)cout<<"男"<<endl;
            if(sex==2)cout<<"女"<<endl;
            else cout<<" "<<endl;
            cout<<"身高："<<height<<" "<<"体重："<<weight<<endl;
            break;
        default:
            cout<<"错误，请重新输入";
            x=1;
            break;
        }
        if(!x)break;
    }
}

void Cperson::size(){
    int a;
    a=sizeof(name)+sizeof(IDnumber)+sizeof(year)+sizeof(mounth)+sizeof(day)+sizeof(sex)+sizeof(height)+sizeof(weight);
    cout<<a;
}
