#include <iostream>

// PaymentStrategy接口
class PaymentStrategy {
public:
    virtual void pay(float amount) = 0;
};

// CreditCardPayment类
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "Credit card payment: $" << amount << std::endl;
        // 实现信用卡支付的具体逻辑
    }
};

// AlipayPayment类
class AlipayPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "Alipay payment: $" << amount << std::endl;
        // 实现支付宝支付的具体逻辑
    }
};

// WechatPayment类
class WechatPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "WeChat payment: $" << amount << std::endl;
        // 实现微信支付的具体逻辑
    }
};

// PaymentProcessor类
class PaymentProcessor {
private:
    PaymentStrategy* paymentStrategy;

public:
    void setPaymentStrategy(PaymentStrategy* strategy) {
        paymentStrategy = strategy;
    }

    void processPayment(float amount) {
        if (paymentStrategy != nullptr) {
            paymentStrategy->pay(amount);
        }
    }
};

int main() {
    // 创建支付策略
    PaymentStrategy* creditCardPayment = new CreditCardPayment();
    PaymentStrategy* alipayPayment = new AlipayPayment();
    PaymentStrategy* wechatPayment = new WechatPayment();

    // 创建支付处理器
    PaymentProcessor paymentProcessor;

    // 使用不同的支付策略进行支付
    paymentProcessor.setPaymentStrategy(creditCardPayment);
    paymentProcessor.processPayment(100.0f);

    paymentProcessor.setPaymentStrategy(alipayPayment);
    paymentProcessor.processPayment(200.0f);

    paymentProcessor.setPaymentStrategy(wechatPayment);
    paymentProcessor.processPayment(300.0f);

    // 释放内存
    delete creditCardPayment;
    delete alipayPayment;
    delete wechatPayment;

    return 0;
}