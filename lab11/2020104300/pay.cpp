#include <iostream>  
#include <string>  
  
// PaymentStrategy 接口  
class PaymentStrategy {  
public:  
    virtual ~PaymentStrategy() {}  
    virtual void pay(float amount) = 0;  
};  
  
// 信用卡支付实现  
class CreditCardPayment : public PaymentStrategy {  
public:  
    void pay(float amount) override {  
        std::cout << "使用信用卡支付: " << amount << std::endl;  
    }  
};  
  
// 支付宝支付实现  
class AlipayPayment : public PaymentStrategy {  
public:  
    void pay(float amount) override {  
        std::cout << "使用支付宝支付: " << amount << std::endl;  
    }  
};  
  
// 微信支付实现  
class WechatPayment : public PaymentStrategy {  
public:  
    void pay(float amount) override {  
        std::cout << "使用微信支付: " << amount << std::endl;  
    }  
};  
  
// PaymentProcessor 类  
class PaymentProcessor {  
public:  
    PaymentProcessor(PaymentStrategy* paymentStrategy) : paymentStrategy(paymentStrategy) {}  
    void processPayment(float amount) {  
        paymentStrategy->pay(amount);  
    }  
private:  
    PaymentStrategy* paymentStrategy;  
};  
  
int main() {  
    // 创建 PaymentProcessor 对象并设置支付策略为信用卡支付  
    PaymentProcessor processor(new CreditCardPayment());  
    processor.processPayment(100.0);  
    delete processor.paymentStrategy; // 释放动态分配的内存  
    std::cout << std::endl;  
  
    // 创建 PaymentProcessor 对象并设置支付策略为支付宝支付  
    processor = PaymentProcessor(new AlipayPayment());  
    processor.processPayment(200.0);  
    delete processor.paymentStrategy; // 释放动态分配的内存  
    std::cout << std::endl;  
  
    // 创建 PaymentProcessor 对象并设置支付策略为微信支付  
    processor = PaymentProcessor(new WechatPayment());  
    processor.processPayment(300.0);  
    delete processor.paymentStrategy; // 释放动态分配的内存  
    std::cout << std::endl;  
    return 0;  
}
