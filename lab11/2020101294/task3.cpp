#include <iostream>

// PaymentStrategy 接口
class PaymentStrategy {
public:
    virtual void pay(float amount) = 0;
};

// CreditCardPayment 类实现 PaymentStrategy 接口
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "Paid " << amount << " via Credit Card." << std::endl;
    }
};

// AlipayPayment 类实现 PaymentStrategy 接口
class AlipayPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "Paid " << amount << " via Alipay." << std::endl;
    }
};

// WechatPayment 类实现 PaymentStrategy 接口
class WechatPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "Paid " << amount << " via Wechat." << std::endl;
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
        if (paymentStrategy) {
            paymentStrategy->pay(amount);
        } else {
            std::cout << "No payment strategy set." << std::endl;
        }
    }
};

// 客户端代码示例
int main() {
    PaymentProcessor processor;

    CreditCardPayment creditCard;
    AlipayPayment alipay;
    WechatPayment wechat;

    // 使用 CreditCardPayment 进行支付
    processor.setPaymentStrategy(&creditCard);
    processor.processPayment(100.0);

    // 使用 AlipayPayment 进行支付
    processor.setPaymentStrategy(&alipay);
    processor.processPayment(50.0);

    // 使用 WechatPayment 进行支付
    processor.setPaymentStrategy(&wechat);
    processor.processPayment(30.0);

    return 0;
}