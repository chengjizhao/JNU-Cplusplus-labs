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
        std::cout << "Paid $" << amount << " via Credit Card." << std::endl;
        // 具体的信用卡支付逻辑
    }
};

// AlipayPayment 类
class AlipayPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "Paid $" << amount << " via Alipay." << std::endl;
        // 具体的支付宝支付逻辑
    }
};

// WechatPayment 类
class WechatPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "Paid $" << amount << " via WeChat Pay." << std::endl;
        // 具体的微信支付逻辑
    }
};

// PaymentProcessor 类
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
    // 创建 PaymentProcessor 对象
    PaymentProcessor processor;

    // 创建不同的支付策略对象
    PaymentStrategy* creditCardPayment = new CreditCardPayment();
    PaymentStrategy* alipayPayment = new AlipayPayment();
    PaymentStrategy* wechatPayment = new WechatPayment();

    // 使用不同的支付策略进行支付
    processor.setPaymentStrategy(creditCardPayment);
    processor.processPayment(100.0f);

    processor.setPaymentStrategy(alipayPayment);
    processor.processPayment(200.0f);

    processor.setPaymentStrategy(wechatPayment);
    processor.processPayment(300.0f);

    // 释放对象的内存
    delete creditCardPayment;
    delete alipayPayment;
    delete wechatPayment;

    return 0;
}
