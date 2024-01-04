#include"lab11.h"

void AlipayPayment::pay(float amount)
{
    cout << "AlipayPayment:" << amount <<endl;
}

void CreditCardPayment::pay(float amount)
{
    cout << "CreditCardPayment:" << amount <<endl;
}

void WechatPayment::pay(float amount)
{
    cout << "WechatPayment:" << amount <<endl;
}
void PaymentProcessor::processPayment(float amount)
{
    this->a->pay(amount);
}

PaymentProcessor::PaymentProcessor(PaymentStrategy *a)
{
    this->a=a;
}

PaymentProcessor::setPaymentStrategy(PaymentStrategy *a)
{
    this->a=a;
}
int main()
{
    PaymentStrategy *a1=new AlipayPayment;
    PaymentStrategy *a2=new CreditCardPayment;
    PaymentStrategy *a3=new WechatPayment;
    PaymentProcessor b(a1);
    b.processPayment(100);
    b.setPaymentStrategy(a2);
    b.processPayment(200);
    b.setPaymentStrategy(a3);
    b.processPayment(300);

}


