#include <iostream>

using namespace std;

/*******************
        Port
*******************/
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
        cout << "Paid by CreditCard: " << amount << " yuan." << endl;
    }
};

class AlipayPayment: public PaymentStrategy
{
public:
    void pay(float amount) override
    {
        cout << "Paid by Alipay: " << amount << " yuan." << endl;
    }
};

class WechatPayment: public PaymentStrategy
{
public:
    void pay(float amount) override
    {
        cout << "Paid by Wechat: " << amount << " yuan." << endl;
    }
};

/*******************
      Strategy
*******************/
class PaymentProcessor
{
private:
    PaymentStrategy* StrategyType;
public:
    PaymentProcessor(PaymentStrategy* StrategyType_input)
    {StrategyType = StrategyType_input;}

    void processPayment(float amount)
    {
        StrategyType->pay(amount);
    }

    void changeStrategy(PaymentStrategy* StrategyType_input)
    {
        StrategyType = StrategyType_input;
        cout << "Strategy changed successfully!" << endl;
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