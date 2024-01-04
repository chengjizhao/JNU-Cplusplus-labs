#pragma once

class PaymentProcessor;

class PaymentStrategy
{
public:
	PaymentStrategy();
	virtual void pay(float amount) = 0;
	friend class PaymentProcessor;
};

class AlipayPayment : public PaymentStrategy
{
public:
	virtual void pay(float amount) override;
	friend class PaymentProcessor;
private:
	AlipayPayment();
};

class CreditCardPayment : public PaymentStrategy
{
public:
	virtual void pay(float amount) override;
	friend class PaymentProcessor;
private:
	CreditCardPayment();
};

class WechatPayment : public PaymentStrategy
{
public:
	virtual void pay(float amount) override;
	friend class PaymentProcessor;
private:
	WechatPayment();
};
