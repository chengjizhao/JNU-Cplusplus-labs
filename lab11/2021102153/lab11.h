#pragma once
#include<iostream>
using namespace std;
class PaymentStrategy
{
public:
	
	virtual void pay(float amount) = 0;
	
};

class AlipayPayment : public PaymentStrategy
{
public:
	virtual void pay(float amount) override;
	
};

class CreditCardPayment : public PaymentStrategy
{
public:
	virtual void pay(float amount) override;
	
};

class WechatPayment : public PaymentStrategy
{
public:
	virtual void pay(float amount) override;
	
};
class PaymentProcessor
{
    public:
    PaymentStrategy *a;
    void processPayment(float amount);
    PaymentProcessor(PaymentStrategy *a);
    setPaymentStrategy(PaymentStrategy *a);
};