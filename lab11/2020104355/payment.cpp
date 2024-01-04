#include <iostream>
using namespace std;
class PaymentStrategy
{
public:
    virtual void pay(float amount) = 0;
};
class CreditCardPayment : public PaymentStrategy
{
public:
    void pay(float amount) override {
        cout << "进行信用卡支付，支付金额：" << amount << endl;
    }
};
class AlipayPayment : public PaymentStrategy
{
public:
    void pay(float amount) override
    {
        cout << "进行支付宝支付，支付金额：" << amount << endl;
    }
};
class WechatPayment : public PaymentStrategy
{
public:
    void pay(float amount) override
    {
        cout << "进行微信支付，支付金额：" << amount << endl;
    }
};
class PaymentProcessor
{
private:
    PaymentStrategy* paymentStrategy;
public:
    void setPaymentStrategy(PaymentStrategy* strategy)
    {
        this->paymentStrategy = strategy;
    }
    void processPayment(float amount) 
    {
        if (paymentStrategy != nullptr)
        {
            paymentStrategy->pay(amount);
        }
    }
};
int main()
{
    PaymentProcessor processor;
    PaymentStrategy* creditCardStrategy = new CreditCardPayment();
    PaymentStrategy* alipayStrategy = new AlipayPayment();
    PaymentStrategy* wechatStrategy = new WechatPayment();
    processor.setPaymentStrategy(creditCardStrategy);
    processor.processPayment(160.0);
    processor.setPaymentStrategy(alipayStrategy);
    processor.processPayment(270.0);
    processor.setPaymentStrategy(wechatStrategy);
    processor.processPayment(390.0);
    delete creditCardStrategy;
    delete alipayStrategy;
    delete wechatStrategy;
    return 0;
}