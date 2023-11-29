#include <iostream>  
  
class PaymentStrategy {  
public:  
    virtual ~PaymentStrategy() {}  
    virtual void pay(float amount) = 0;  
};

class CreditCardPayment : public PaymentStrategy {  
public:  
    void pay(float amount) override {  
        std::cout << "Using credit card to pay: " << amount << std::endl;  
    }  
};  
  

class AlipayPayment : public PaymentStrategy {  
public:  
    void pay(float amount) override {  
        std::cout << "Using Alipay to pay: " << amount << std::endl;  
    }  
};  
  

class WechatPayment : public PaymentStrategy {  
public:  
    void pay(float amount) override {  
        std::cout << "Using Wechat to pay: " << amount << std::endl;  
    }  
};
  
class PaymentProcessor {  
private:  
    PaymentStrategy* paymentStrategy;  
public:  
    void setPaymentStrategy(PaymentStrategy* strategy) {  
        paymentStrategy = strategy;  
    }  
    void processPayment(float amount) {  
        paymentStrategy->pay(amount);  
    }  
};

int main() {  
    CreditCardPayment creditCardPayment;  
    AlipayPayment alipayPayment;  
    WechatPayment wechatPayment;  
    PaymentProcessor processor;  
    processor.setPaymentStrategy(&creditCardPayment);  
    processor.processPayment(100.0); // Output: Using credit card to pay: 100.0   
    processor.setPaymentStrategy(&alipayPayment);   
    processor.processPayment(200.0); // Output: Using Alipay to pay: 200.0   
    processor.setPaymentStrategy(&wechatPayment);   
    processor.processPayment(300.0); // Output: Using Wechat to pay: 300.0      
    return 0;     
}