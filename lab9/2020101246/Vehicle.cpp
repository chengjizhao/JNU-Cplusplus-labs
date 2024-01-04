#include<iostream>
#include<string>
using namespace std;


class Vehicle{
    public:
    int speed;
    Vehicle(){};
    Vehicle(int x){speed=x;};
    void virtual start(){};
};

class Car :public virtual Vehicle{
    private:
    float ton;
    public:
    Car(){};
    void CC_ton(const float & n){ton=n;};
    Car(const int & C_speed,const float & n){speed=C_speed;CC_ton(n);};
    void start () override {cout<<"this is car : "<<ton<<"  speed\a "<<speed<<endl;};

};

class Boat :public virtual Vehicle {
    private:
    float ton;
    public:
    Boat(){};
    void N_ton(const float & n){ton=n;};
    Boat(const int & P_speed,const float & n){speed=P_speed;N_ton(n);};
    void start () override {cout<<"this is Boat : "<<ton<<endl;};
};

class SmartDevice:public Car,public Boat{
    public:
     SmartDevice(){};
     string ton;
     SmartDevice(const int & pri,const float & x,const string & na):Vehicle(pri),Car(pri,x),Boat(pri,x){ton=na;};
     void start ()override
     {
        if(ton=="Car")
        {Car::start();}
        else if(ton=="Boat")
        {Boat::start();}
        else{cout<<"mistake"<<endl;};

     };
};

int main(){
    SmartDevice C_Com(100,10,"Car");
    C_Com.start();
    cout<<C_Com.ton;
    return 0;
}