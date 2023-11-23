#include <iostream>  
#include <string>  
using namespace std;

class PaymentStrategy {  
public:  
    virtual ~PaymentStrategy() {}  
    virtual void pay(float amount) = 0;  
};  

class CreditCardPayment : public PaymentStrategy 
{  
public:  

    void pay(float amount) 
     {  
        cout << "使用信用卡支付: " << amount << endl;  
    }  
};  
  

class AlipayPayment : public PaymentStrategy 
{  
public:  
    void pay(float amount) 
    {  
        cout << "使用支付宝支付: " << amount << endl;  
    }  
};  
  
class WechatPayment : public PaymentStrategy 
{  
public:  
    void pay(float amount) 
     {  
        cout << "使用微信支付: " << amount << endl;  
    }  
};  
  
class PaymentProcessor {  
public:  
    PaymentProcessor(PaymentStrategy* payment_strategy) : payment_strategy(payment_strategy) {}  
    void processPayment(float amount)
     {  
        payment_strategy->pay(amount);  
    }  

private:  
    PaymentStrategy* payment_strategy;  
};  
  
int main()
{  
    PaymentStrategy *p = new CreditCardPayment;
    PaymentProcessor pay(p);
    pay.processPayment(60);
 
    p = new AlipayPayment;
    pay.processPayment(99);
  
    p = new WechatPayment;
    pay.processPayment(200);
    delete p;
    return 0;
}