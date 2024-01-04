#ifndef  __ECOMMERCE_PAYMENT_SYSTEM_H
#define  __ECOMMERCE_PAYMENT_SYSTEM_H
#include <iostream>

// PaymentStrategy 接口
class PaymentStrategy {
public:
    virtual void pay(float amount) = 0;
};

// CreditCardPayment 类
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "Paid " << amount << " using Credit Card." << std::endl;
        // 实际支付逻辑
    }
};

// AlipayPayment 类
class AlipayPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "Paid " << amount << " using Alipay." << std::endl;
        // 实际支付逻辑
    }
};

// WechatPayment 类
class WechatPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "Paid " << amount << " using Wechat Pay." << std::endl;
        // 实际支付逻辑
    }
};

// PaymentProcessor 类
class PaymentProcessor {
private:
    PaymentStrategy* paymentStrategy;

public:
    PaymentProcessor(PaymentStrategy* strategy) : paymentStrategy(strategy) {}

    void setPaymentStrategy(PaymentStrategy* strategy) {
        paymentStrategy = strategy;
    }

    void processPayment(float amount) {
        paymentStrategy->pay(amount);
    }
};

#endif