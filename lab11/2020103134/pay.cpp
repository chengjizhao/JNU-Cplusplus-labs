#include<iostream>
using namespace std;

class PaymentStrategy{
    public:
    virtual void pay(float amount)=0;
};

class CreditCardPayment:public PaymentStrategy{
    public:
    void pay(float amount) override{
        cout<<"信用卡支付金额为"<<amount<<endl;
    }
};

class AlipayPayment:public PaymentStrategy{
    public:
    void pay(float amount) override{
        cout<<"支付宝支付金额为"<<amount<<endl;
    }
};

class WechatPayment:public PaymentStrategy{
    public:
    void pay(float amount) override{
        cout<<"微信支付金额为"<<amount<<endl;
    }
};

class PaymentProcessor{
    PaymentStrategy& strategy;
    public:
    PaymentProcessor(PaymentStrategy& strat):strategy(strat){}
    void pay(float amount){
        strategy.pay(amount);
    }
};

int main(){
    CreditCardPayment CCP;
    AlipayPayment AP;
    WechatPayment WP;
    PaymentProcessor p1(CCP),p2(AP),p3(WP);
    p1.pay(1.0);
    p2.pay(2.0);
    p3.pay(3.0);
}