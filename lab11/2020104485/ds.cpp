#include <iostream>

// 支付策略接口
class PaymentStrategy {
public:
 virtual void pay(float amount) =0;
};

//信用卡支付
class CreditCardPayment : public PaymentStrategy {
public:
 void pay(float amount) override {
 std::cout << "Paying " << amount << " via Credit Card." << std::endl;
 }
};

// 支付宝支付
class AlipayPayment : public PaymentStrategy {
public:
 void pay(float amount) override {
 std::cout << "Paying " << amount << " via Alipay." << std::endl;
 }
};

// 微信支付
class WechatPayment : public PaymentStrategy {
public:
 void pay(float amount) override {
 std::cout << "Paying " << amount << " via Wechat Pay." << std::endl;
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

int main() {
 PaymentStrategy* creditCardPayment = new CreditCardPayment();
 PaymentStrategy* alipayPayment = new AlipayPayment();
 PaymentStrategy* wechatPayment = new WechatPayment();

 PaymentProcessor processor(creditCardPayment);
 processor.processPayment(100.0f);

 processor.setPaymentStrategy(alipayPayment);
 processor.processPayment(200.0f);

 processor.setPaymentStrategy(wechatPayment);
 processor.processPayment(300.0f);

 delete creditCardPayment;
 delete alipayPayment;
 delete wechatPayment;

 return 0;
}
