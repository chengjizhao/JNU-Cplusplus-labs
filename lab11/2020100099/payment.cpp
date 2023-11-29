#include <iostream>

// PaymentStrategy接口
class PaymentStrategy {
public:
    virtual void pay(float amount) = 0;
};

// 信用卡支付类
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "使用信用卡支付：" << amount << std::endl;
    }
};

// 支付宝支付类
class AlipayPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "使用支付宝支付：" << amount << std::endl;
    }
};

// 微信支付类
class WechatPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "使用微信支付：" << amount << std::endl;
    }
};

// PaymentProcessor类
class PaymentProcessor {
private:
    PaymentStrategy* payment_strategy;

public:
    PaymentProcessor(PaymentStrategy* strategy) : payment_strategy(strategy) {}

    void processPayment(float amount) {
        payment_strategy->pay(amount);
    }
};

int main() {
    // 创建不同的支付策略对象
    PaymentStrategy* credit_card_payment = new CreditCardPayment();
    PaymentStrategy* alipay_payment = new AlipayPayment();
    PaymentStrategy* wechat_payment = new WechatPayment();

    // 创建PaymentProcessor对象，并设置不同的支付策略
    PaymentProcessor* payment_processor = new PaymentProcessor(credit_card_payment);
    payment_processor->processPayment(100.0);

    payment_processor->processPayment(200.0);
    payment_processor->processPayment(300.0);

    // 释放内存
    delete credit_card_payment;
    delete alipay_payment;
    delete wechat_payment;
    delete payment_processor;

    return 0;
}
