#include<iostream>
#include<string>
#include"text5.h"
using namespace std;
int main()
{
    Person p1;
    Person p2(1);
    Person p3(1,2);
    int n;
    while(n<13)
    {
    cout<<"请选择您需要实现的功能："<<endl;
    cout<<"1、输入姓名"<<"\t"<<"2、显示姓名"<<"\t"<<"3、输入ID"<<endl;
    cout<<"4、显示ID"<<"\t"<<"5、输入生日"<<"\t"<<"6、显示生日"<<endl;
    cout<<"7、输入性别"<<"\t"<<"8、显示性别"<<"\t"<<"9、输入身高"<<endl;
    cout<<"10、显示身高"<<"\t"<<"11、输入体重"<<"\t"<<"12、显示体重"<<endl;
    cout<<"13、退出"<<endl;
    cin>>n;
    switch(n)
    {   
        case 1:
        {
        cout<<"请输入您的姓名："<<endl;
        cin>>p1.Name;
        cout<<"输入成功！！"<<endl;
        break;
        }

        case 2:
        {
        cout<<"您的名字为："<<p1.Name<<endl;
        break;
        }

        case 3:
        {
        p1.setId();
        break;
        }

        case 4:
        {
        p1.getId();
        break;
        }

        case 5:
        {
        p1.setBorn();
        break;
        }

        case 6:
        {
        p1.getBorn();
        break;
        }

        case 7:
        {
        p1.setSex();
        break;
        }

        case 8:
        {
        p1.getSex();
        break;
        }

        case 9:
        {
        p1.setHigh();
        break;
        }
        
        case 10:
        {
        p1.getHigh();
        break;
        }
        
        case 11:
        {
        p1.setWeight();
        break;
        }

        case 12:
        {
        p1.getWeight();
        break;
        }

        default:
        {}
    }
    }
    

    //p1.setId();
    //p1.getId();
    //p1.setBorn();
    //p1.getBorn();
    //p1.setSex();
    //p1.getSex();
    //p1.setHigh();
    //p1.getHigh();    
    //p1.setWeight();
    //p1.getWeight();
    return 0;
}