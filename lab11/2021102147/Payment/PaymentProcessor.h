#pragma once
#include "PaymentStrategy.h"

enum PaymentType
{
	Alipay,
	Wechat,
	CreditCard
};

class PaymentProcessor
{
public:
	PaymentProcessor(PaymentType pt);
	~PaymentProcessor();
	void setPaymentStrategy(PaymentType pt);
	void processPayment(float amount);
private:
	PaymentStrategy* _strategy;
};

