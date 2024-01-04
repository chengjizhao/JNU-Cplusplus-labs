#include <iostream>  
#include <string>  
   
class PaymentStrategy
{  
public:  
    virtual ~PaymentStrategy() {}  
    virtual void pay(float amount) = 0;  
};  
 
class CreditCardPayment : public PaymentStrategy
{  
public:  
    void pay(float amount) override 
    {  
        std::cout << "使用信用卡支付: " << amount << std::endl;  
    }  
};  

class AlipayPayment : public PaymentStrategy 
{  
public:  
    void pay(float amount) override 
    {  
        std::cout << "使用支付宝支付: " << amount << std::endl;  
    }  
};  
  
// 微信支付实现  
class WechatPayment : public PaymentStrategy 
{  
public:  
    void pay(float amount) override 
    {  
        std::cout << "使用微信支付: " << amount << std::endl;  
    }  
};  
   
class PaymentProcessor 
{  
public:  
    PaymentProcessor(PaymentStrategy* paymentStrategy) : paymentStrategy(paymentStrategy) {}  
    void processPayment(float amount) 
    {  
        paymentStrategy->pay(amount);  
    }  
private:  
    PaymentStrategy* paymentStrategy;  
};  
  
int main() 
{  
    PaymentProcessor processor(new CreditCardPayment());  
    processor.processPayment(100.0);  
    delete processor.paymentStrategy 
    std::cout << std::endl;  
  
    processor = PaymentProcessor(new AlipayPayment());  
    processor.processPayment(200.0);  
    delete processor.paymentStrategy;  
    std::cout << std::endl;  
  
    processor = PaymentProcessor(new WechatPayment());  
    processor.processPayment(300.0);  
    delete processor.paymentStrategy;
    std::cout << std::endl;  
    return 0;  
}