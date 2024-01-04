#include<iostream>
#include"class.h"
using namespace std;
static int AAA=5;
static int BBB=4;

int main()
{
   Classic IA; //一般类
   Bclassic IB;//一般继承
   ClassVIr IIA;//
   BClassVIr IIB;
   Basic XA;
   Father XB;
   son XC;
   BasicVir XI;
   FaVirr XII;
   SonVir XIII;
   cout<<"一般类对象成员地址"<<endl;
   cout<<&IA.a<<endl;
   cout<<"一般类继承对象成员地址"<<endl;
   cout<<&IB.a<<endl;
   cout<<&IB.b<<endl;
   cout<<"一般类带虚函数对象成员地址"<<endl;
   cout<<&IIA.a<<endl;
   cout<<"一般类带虚函数对象虚函数表地址"<<endl;
   int* vtptr=(int*)(&IIA);
   int* ptr=(int*)(*vtptr);
   cout<<ptr<<endl;
   cout<<"一般继承类带虚函数对象成员地址"<<endl;
   cout<<&IIB.a<<endl;
   cout<<&IIB.b<<endl;
   cout<<"一般类带虚函数对象虚函数表地址"<<endl;
   int* Vvtptr=(int*)(&IIB);
   int* Vptr=(int*)(*Vvtptr);
   cout<<Vptr<<endl;
   cout<<"棱形继承基类成员对象地址"<<endl;
   cout<<&XA.data<<endl;
   cout<<"基类虚函数表地址"<<endl;
   cout<<"一般类带虚函数对象虚函数表地址"<<endl;
   int* Bvtptr=(int*)(&XA);
   int* Bptr=(int*)(*Bvtptr);
   cout<<Bptr<<endl;
   cout<<"棱形继承父类成员对象地址"<<endl;
   cout<<&XB.data<<endl;
   cout<<"父类虚函数表地址"<<endl;
   int* Fvtptr=(int*)(&XB);
   int* Fptr=(int*)(*Fvtptr);
   cout<<Fptr<<endl;
   cout<<"棱形继承子类成员对象地址"<<endl;
   cout<<&XC.Father::data<<endl;
   cout<<&XC.mother::data<<endl;
   cout<<&XC.baby<<endl;
   cout<<"子类虚函数表地址"<<endl;
   int* svtptr=(int*)(&XC);
   int* sptr=(int*)(*svtptr);
   cout<<"虚继承基类成员对象地址"<<endl;
   cout<<&XI.data<<endl;
   cout<<"基类对象虚函数表地址"<<endl;
   int* Bbvtptr=(int*)(&XI);
   int* Bbptr=(int*)(*Bbvtptr);
   cout<<Bbptr<<endl;
   cout<<"父类成员对象地址"<<endl;
   cout<<&XII.data<<endl;
   cout<<"父类成员虚函数表"<<endl;
   int* Fvvtptr=(int*)(&XII);
   int* Fiptr=(int*)(*Fvvtptr);
   cout<<Fiptr<<endl;
   cout<<"子类对象成员地址"<<endl;
   cout<<&XIII.data<<endl;
   cout<<&XIII.baby<<endl;
   cout<<"子类对象虚函数表地址"<<endl;
   int* SOvtptr=(int*)(&XIII);
   int* SOptr=(int*)(*SOvtptr);
   cout<<SOptr<<endl;






return 0;

}
