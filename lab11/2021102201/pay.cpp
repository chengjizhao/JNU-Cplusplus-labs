#include <iostream>

using namespace std;

class PaymentStrategy
{
public:
    virtual void pay(float amount) = 0;
};

class CreditCardPayment: public PaymentStrategy
{
public:
    void pay(float amount) override
    {
        cout << "从信用卡中支付了 " << amount << " 元。" << endl;
    }
};

class AlipayPayment: public PaymentStrategy
{
public:
    void pay(float amount) override
    {
        cout << "从支付宝中支付了" << amount << " 元。" << endl;
    }
};

class WechatPayment: public PaymentStrategy
{
public:
    void pay(float amount) override
    {
        cout << "从微信中支付了" << amount << " 元。" << endl;
    }
};

class PaymentProcessor
{
private:
    PaymentStrategy* StrategyType;

public:
    PaymentProcessor(PaymentStrategy* StrategyType_input)
    {
        StrategyType = StrategyType_input;
    }
    void processPayment(float amount)
    {
        StrategyType->pay(amount);
    }
    void changeStrategy(PaymentStrategy* StrategyType_input)
    {
        StrategyType = StrategyType_input;
        cout << "成功切换支付方式。" << endl;
    }
};



int main()
{
    PaymentStrategy* strategy1  = new CreditCardPayment;
    PaymentStrategy* strategy2  = new AlipayPayment;
    PaymentProcessor processor(strategy1);
    
    processor.processPayment(100);
    processor.changeStrategy(strategy2);
    processor.processPayment(200);

    delete strategy1;
    return 0;
}