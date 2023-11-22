
class PaymentStrategy {
public:
    virtual void pay(float amount) = 0;
    virtual ~PaymentStrategy() {}
};



#include <iostream>

class CreditCardPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "Paying " << amount << " via Credit Card" << std::endl;
        // 实现信用卡支付逻辑
    }
};

class AlipayPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "Paying " << amount << " via Alipay" << std::endl;
        // 实现支付宝支付逻辑
    }
};

class WechatPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "Paying " << amount << " via Wechat Pay" << std::endl;
        // 实现微信支付逻辑
    }
};
class PaymentProcessor {
private:
    PaymentStrategy *paymentStrategy;

public:
    PaymentProcessor() : paymentStrategy(nullptr) {}

    void setPaymentStrategy(PaymentStrategy *strategy) {
        paymentStrategy = strategy;
    }

    void processPayment(float amount) {
        if (paymentStrategy) {
            paymentStrategy->pay(amount);
        } else {
            std::cout << "No payment strategy set." << std::endl;
        }
    }
};
int main() {
    PaymentProcessor processor;

    // 使用信用卡支付
    CreditCardPayment creditCard;
    processor.setPaymentStrategy(&creditCard);
    processor.processPayment(100.0f);

    // 使用支付宝支付
    AlipayPayment alipay;
    processor.setPaymentStrategy(&alipay);
    processor.processPayment(50.0f);

    // 使用微信支付
    WechatPayment wechat;
    processor.setPaymentStrategy(&wechat);
    processor.processPayment(30.0f);

    return 0;
}
/*
UML图:
+-------------------+        +----------------------+
| PaymentStrategy   |<-------|   CreditCardPayment  |
|-------------------|        |----------------------|
| + pay(float): void |        | + pay(float): void   |
+-------------------+        +----------------------+
         ^
         |
+-------------------+        +----------------------+
| PaymentProcessor  |        |    AlipayPayment     |
|-------------------|        |----------------------|
| - paymentStrategy |<>------| + pay(float): void   |
+-------------------+        +----------------------+
                               ^
                               |
                          +----------------------+
                          |   WechatPayment      |
                          |----------------------|
                          | + pay(float): void   |
                          +----------------------+
*/