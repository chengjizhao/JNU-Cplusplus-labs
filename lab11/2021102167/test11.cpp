class PaymentStrategy {
public:
    virtual void pay(float amount) = 0;
};

class CreditCardPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
    }
};

class AlipayPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
    }
};
class WechatPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
    }
};
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
    PaymentStrategy* creditCard = new CreditCardPayment();
    PaymentStrategy* alipay = new AlipayPayment();
    PaymentStrategy* wechat = new WechatPayment();

    PaymentProcessor processor(creditCard);
    processor.processPayment(100.0); // 使用信用卡支付100元

    processor.setPaymentStrategy(alipay);
    processor.processPayment(200.0); // 使用支付宝支付200元

    processor.setPaymentStrategy(wechat);
    processor.processPayment(300.0); // 使用微信支付300元

    delete creditCard;
    delete alipay;
    delete wechat;

    return 0;
}