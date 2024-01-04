#include <iostream>
using namespace std;

// 支付策略接口
class PaymentStrategy {
public:
    virtual void pay(float amount) = 0;
};

// 信用卡支付
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        cout << "Paying " << amount << " via credit card." << endl;
        // 在此处实现具体的信用卡支付逻辑
    }
};

// 支付宝支付
class AlipayPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        cout << "Paying " << amount << " via Alipay." << endl;
        // 在此处实现具体的支付宝支付逻辑
    }
};

// 微信支付
class WechatPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        cout << "Paying " << amount << " via WeChat Pay." << endl;
        // 在此处实现具体的微信支付逻辑
    }
};

// 支付处理器
class PaymentProcessor {
private:
    PaymentStrategy* paymentStrategy;

public:
    PaymentProcessor(PaymentStrategy* strategy) : paymentStrategy(strategy) {}

    void processPayment(float amount) {
        paymentStrategy->pay(amount);
    }
};

int main() {
    PaymentStrategy* creditCardPayment = new CreditCardPayment();
    PaymentStrategy* alipayPayment = new AlipayPayment();
    PaymentStrategy* wechatPayment = new WechatPayment();

    PaymentProcessor processor(creditCardPayment);
    processor.processPayment(100.0);

    processor = PaymentProcessor(alipayPayment);
    processor.processPayment(200.0);

    processor = PaymentProcessor(wechatPayment);
    processor.processPayment(300.0);

    delete creditCardPayment;
    delete alipayPayment;
    delete wechatPayment;

    return 0;
}
