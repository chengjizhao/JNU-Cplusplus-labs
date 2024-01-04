#include <iostream>

// PaymentStrategy.h

class PaymentStrategy {
public:
    virtual void pay(float amount) = 0;
};

// CreditCardPayment.h

class CreditCardPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "使用信用卡支付：" << amount << "元" << std::endl;
    }
};

// AlipayPayment.h

class AlipayPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "使用支付宝支付：" << amount << "元" << std::endl;
    }
};

// WechatPayment.h

class WechatPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "使用微信支付：" << amount << "元" << std::endl;
    }
};

// PaymentProcessor.h

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

// main.cpp

int main() {
    PaymentProcessor processor;

    CreditCardPayment creditCardPayment;
    processor.setPaymentStrategy(&creditCardPayment);
    processor.processPayment(100.0);

    AlipayPayment alipayPayment;
    processor.setPaymentStrategy(&alipayPayment);
    processor.processPayment(200.0);

    WechatPayment wechatPayment;
    processor.setPaymentStrategy(&wechatPayment);
    processor.processPayment(300.0);

    return 0;
}