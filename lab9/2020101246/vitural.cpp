#include<iostream>
#include<string>
using namespace std;


class Device{
    public:
    int price;
    Device(){};
    void virtual runapp(){};
};

class Computer :public Device{
    private:
    string name;
    public:
    Computer(){};
    void N_name(string n){name=n;};
    Computer(const int & C_value,const string & n){price=C_value;N_name(n);};
    void runapp () override {cout<<"this is computer : "<<endl;};

};
//class Phone:public virtual Device 虚继承
class Phone :public Device {
    private:
    string name;
    public:
    Phone(){};
    void N_name(string n){name=n;};
    Phone(const int & P_value,const string & n){price=P_value;N_name(n);};
    void runapp () override {cout<<"this is phone : "<<endl;};
};

class SmartDevice:public Computer,public Phone{
    public:
     void  C_runApp(){Computer::runapp();};
     void  P_runApp(){Phone::runapp();};
     SmartDevice(){};
     SmartDevice(const int & pri,const string & x)
     {
        string c="computer";
        string ph="phone";
        if (x==c)
        {Computer(pri,x);}
        else
        {Phone(pri,x);}
     };


};

int main(){
    SmartDevice C_Com(100,"computer");
   C_Com.Computer::runapp(); // 不用虚继承会导致二义性问题，故使用::指定作用域
   //报错例子： C_Com.runapp()

    int number;
    string nam;
    cout<<"Enter price"<<endl;
    (cin>>number).get();
    cout<<"Enter name\n";
    cin>>nam;
   SmartDevice choice(number,nam);
        string ccc="computer";
        string phhh="phone";
        if (nam==ccc)
     {choice.Computer::runapp();}
        else if(nam==phhh)
     {choice.Phone::runapp();}
     else 
      {cout<<"wrong input"<<endl;};
    return 0;
}