#include <iostream>

using namespace std;

class PaymentStrategy
{
    public:
        virtual void pay(float amoount) = 0;
        virtual ~PaymentStrategy() {}
};

class CreditCardPayment : public PaymentStrategy
{
    public:
        void pay(float amount) override
        {
            cout << "paid " << amount << " via credit card" << endl;
        }
};

class AlipayPayment : public PaymentStrategy
{
    public:
        void pay(float amount) override
        {
            cout << "paid " << amount << " via alipay" << endl;
        }
};

class WechatPayment : public PaymentStrategy
{
    public:
        void pay(float amount) override
        {
            cout << "paid " << amount << " via wechat pay" << endl;
        }
};

class PaymentProcessor
{
    private:
        PaymentStrategy* paymentStrategy;
    public:
        PaymentProcessor(PaymentStrategy* strategy) : paymentStrategy(strategy) {}
        void setPaymentStrategy(PaymentStrategy* strategy)
        {
            paymentStrategy = strategy;
        }
        void processPayment(float amount)
        {
            paymentStrategy->pay(amount);
        }
};

int main()
{
    PaymentStrategy* CreditCard = new CreditCardPayment();
    PaymentStrategy* Alipay = new AlipayPayment();
    PaymentStrategy* Wechat = new WechatPayment();

    PaymentProcessor processor(CreditCard);
    processor.processPayment(100);

    processor.setPaymentStrategy(Alipay);
    processor.processPayment(80);

    processor.setPaymentStrategy(Wechat);
    processor.processPayment(50);

    delete CreditCard;
    delete Alipay;
    delete Wechat;

    return 0;
}