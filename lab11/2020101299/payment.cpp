#include <iostream>  
  
class PaymentStrategy {  
public:  
    virtual ~PaymentStrategy() {}  
    virtual void pay(float amount) = 0;  
};  
  
class CreditCardPayment : public PaymentStrategy {  
public:  
    void pay(float amount) override {  
        std::cout << "使用信用卡支付：" << amount << " 元" << std::endl;  
    }  
};  
  
class AlipayPayment : public PaymentStrategy {  
public:  
    void pay(float amount) override {  
        std::cout << "使用支付宝支付：" << amount << " 元" << std::endl;  
    }  
};  
  
class WechatPayment : public PaymentStrategy {  
public:  
    void pay(float amount) override {  
        std::cout << "使用微信支付：" << amount << " 元" << std::endl;  
    }  
};  
  
class PaymentProcessor {  
public:  
    void setPaymentStrategy(PaymentStrategy* strategy) {  
        paymentStrategy = strategy;  
    }  
  
    void processPayment(float amount) {  
        paymentStrategy->pay(amount);  
    }  
private:  
    PaymentStrategy* paymentStrategy;  
};  
  
int main() {  
    // 创建不同的支付策略对象  
    CreditCardPayment creditCardPayment;  
    AlipayPayment alipayPayment;  
    WechatPayment wechatPayment;  
  
    // 创建 PaymentProcessor 对象，并设置支付策略为信用卡支付  
    PaymentProcessor processor;  
    processor.setPaymentStrategy(&creditCardPayment);  
  
    // 处理支付请求，使用信用卡支付方式进行支付  
    float amount = 100.0;  // 待支付金额（单位：元）  
    processor.processPayment(amount);  
  
    // 设置支付策略为支付宝支付，并再次处理支付请求  
    processor.setPaymentStrategy(&alipayPayment);  
    processor.processPayment(amount);  
  
    // 设置支付策略为微信支付，并再次处理支付请求  
    processor.setPaymentStrategy(&wechatPayment);  
    processor.processPayment(amount);  
  
    return 0;  
}