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
            cout << "Credit Card: " << amount << endl;
        }
};

class AlipayPayment : public PaymentStrategy 
{
    public:
        void pay(float amount) override {
            cout << "Alipay: " << amount << endl;
        }
};

class WechatPayment : public PaymentStrategy 
{
    public:
        void pay(float amount) override {
            cout << "WeChat: " << amount << endl;
    }
};

class PaymentProcessor 
{
    private:
        PaymentStrategy* strategy;
    public:
        PaymentProcessor(PaymentStrategy* strategy) : strategy(strategy) {}

    void set_PaymentStrategy(PaymentStrategy* newStrategy) {
        strategy = newStrategy;
    }
    void perform_Payment(float amount) {
        strategy -> pay(amount);
    }
};

int main() 
{
    CreditCardPayment CreditCard_obj;
    AlipayPayment Alipay_obj;
    WechatPayment WeChat_obj;

    PaymentProcessor paymentProcessor(&CreditCard_obj);

    paymentProcessor.perform_Payment(1.0);  

    paymentProcessor.set_PaymentStrategy(&Alipay_obj);
    paymentProcessor.perform_Payment(2.0);  

    paymentProcessor.set_PaymentStrategy(&WeChat_obj);
    paymentProcessor.perform_Payment(3.0);   

    return 0;
}