#include <iostream>  
#include <memory>  
  
class PaymentStrategy {  
public:  
    virtual ~PaymentStrategy() = default;  
    virtual void pay(float amount) = 0;  
};  
  
class CreditCardPayment : public PaymentStrategy {  
public:  
    void pay(float amount) override {  
        std::cout << "使用信用卡支付 " << amount << " 元" << std::endl;  
    }  
};  
  
class AlipayPayment : public PaymentStrategy {  
public:  
    void pay(float amount) override {  
        std::cout << "使用支付宝支付 " << amount << " 元" << std::endl;  
    }  
};  
  
class WechatPayment : public PaymentStrategy {  
public:  
    void pay(float amount) override {  
        std::cout << "使用微信支付 " << amount << " 元" << std::endl;  
    }  
};  
  
class PaymentProcessor {  
public:  
    PaymentProcessor() = default;  
    PaymentProcessor(std::shared_ptr<PaymentStrategy> strategy) : strategy(strategy) {}  
  
    void setPaymentStrategy(std::shared_ptr<PaymentStrategy> strategy) {  
        this->strategy = strategy;  
    }  
  
    void processPayment(float amount) {  
        if (strategy) {  
            strategy->pay(amount);  
        } else {  
            std::cout << "没有设置支付策略" << std::endl;  
        }  
    }  
  
private:  
    std::shared_ptr<PaymentStrategy> strategy;  
};  
  
int main() {  
    // 创建 PaymentProcessor 对象  
    PaymentProcessor processor;  
  
    // 信用卡支付对象  
    std::shared_ptr<CreditCardPayment> creditCardStrategy = std::make_shared<CreditCardPayment>();  
    processor.setPaymentStrategy(creditCardStrategy);  
    processor.processPayment(100.0); // 信用卡支付 100.0 金额  
  
    // 支付宝支付对象 
    std::shared_ptr<AlipayPayment> alipayStrategy = std::make_shared<AlipayPayment>();  
    processor.setPaymentStrategy(alipayStrategy);  
    processor.processPayment(200.0); // 支付宝支付 200.0 金额  
  
    // 微信支付对象
    std::shared_ptr<WechatPayment> wechatStrategy = std::make_shared<WechatPayment>();  
    processor.setPaymentStrategy(wechatStrategy);  
    processor.processPayment(300.0); // 微信支付 300.0 金额  
  
    return 0;  
}