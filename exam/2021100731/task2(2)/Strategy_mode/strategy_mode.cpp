#include <iostream>

using namespace std;

/*策略*/
class PaymentStrategy
{
public:
    virtual void pay(int amount) = 0;
};

class CreditCardPayment: public PaymentStrategy
{
public:
    void pay(int amount) override
    {
        cout << "Paid by CreditCard: " << amount << " yuan." << endl;
    }
};

class ChequePayment: public PaymentStrategy
{
public:
    void pay(int amount) override
    {
        cout << "Paid by Cheque: " << amount << " yuan." << endl;
    }
};


/*接口*/
class PaymentProcessor
{
private:
    PaymentStrategy* StrategyType;
public:
    PaymentProcessor(PaymentStrategy* input)
    {StrategyType = input;}

    void processPayment(float amount)
    {
        StrategyType->pay(amount);
    }

    void changeStrategy(PaymentStrategy* input)
    {
        StrategyType = input;
        cout << "Strategy changed successfully!" << endl;
    }
};




int main()
{
    PaymentStrategy* strategy1  = new CreditCardPayment;
    PaymentStrategy* strategy2  = new ChequePayment;

    PaymentProcessor processor(strategy1);
    processor.processPayment(100);
    processor.changeStrategy(strategy2);
    processor.processPayment(200);

    delete strategy1;
    delete strategy2;

    return 0;
}