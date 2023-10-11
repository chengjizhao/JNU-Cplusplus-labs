#include<iostream>
#include"person.h"
#include<string>
using namespace std;
Self::Self(){}
Self::Self(std::string n, std::string i, std::string b, std::string g, int h, int w): name(n), id_number(i), brith(b), sex(g), height(h), weight(w) {}
void Self::People()
{
std::cout<<"name: "<<name<<std::endl<<"id: "<<"\n"<<id_number
         <<"brithday: "<<brith<<std::endl<<"sexual: "<<sex<<std::endl<<"height: "<<height<<endl<<"weight:: "<<weight<<endl;
}

void Self::Exchange(int n)
{
    int choice;
    choice=n;
    switch(choice)
    {
        case 1:cout<<"last id: "<<id_number<<endl<<"Enter: ";
        cin>>id_number;
        cout<<"now: "<<id_number<<endl;
        break;
        case 2:cout<<"last brithday: "<<brith<<endl<<"Enter: ";
        cin>>brith;
        cout<<"now: "<<brith<<endl;
        break;
        case 3:cout<<"last sexual: "<<sex<<endl<<"Enter: ";
        cin>>sex;
        cout<<"now: "<<sex<<endl;
        break;
        case 4:cout<<"last height: "<<height<<endl<<"Enter: ";
        cin>>height;
        cout<<"now: "<<height<<endl;
        break;
        case 5:cout<<"last weight: "<<weight<<endl<<"Enter: ";
        cin >>weight;
        cout <<"now: "<<weight<<endl;
        break;
        case 6:
        break;
    }
}
