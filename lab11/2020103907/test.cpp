#include <iostream>
using namespace std;

// 定义支付策略接口
class PaymentStrategy {
public:
    virtual void pay(float amount) const = 0;
    virtual ~PaymentStrategy() {}
};

// 信用卡支付
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(float amount) const override {
        cout << "Paid " << amount << " RMB via Credit Card" << endl;
    }
};

// 支付宝支付
class AlipayPayment : public PaymentStrategy {
public:
    void pay(float amount) const override {
        cout << "Paid " << amount << " RMB via Alipay" << endl;
    }
};

// 微信支付
class WechatPayment : public PaymentStrategy {
public:
    void pay(float amount) const override {
        cout << "Paid " << amount << " RMB via Wechat Pay" << endl;
    }
};

// 支付处理器
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

// 客户端代码
int main() {
    // 创建不同的支付方式
    CreditCardPayment creditCardPayment;
    AlipayPayment alipayPayment;
    WechatPayment wechatPayment;

    // 创建支付处理器并设置支付方式
    PaymentProcessor paymentProcessor(&creditCardPayment);

    // 进行支付
    paymentProcessor.processPayment(3000.0);

    // 切换到支付宝支付
    paymentProcessor.setPaymentStrategy(&alipayPayment);

    // 进行支付
    paymentProcessor.processPayment(2000.0);

    // 切换到微信支付
    paymentProcessor.setPaymentStrategy(&wechatPayment);

    // 进行支付
    paymentProcessor.processPayment(1000.0);

    return 0;
}
