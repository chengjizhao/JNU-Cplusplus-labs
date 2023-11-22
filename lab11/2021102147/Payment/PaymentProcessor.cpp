#include "PaymentProcessor.h"

void PaymentProcessor::setPaymentStrategy(PaymentType pt)
{
	if (_strategy != nullptr)
	{
		delete _strategy;
		_strategy = nullptr;
	}

	switch (pt)
	{
	case Alipay:
		_strategy = new AlipayPayment;
		break;
	case Wechat:
		_strategy = new WechatPayment;
		break;

	case CreditCard:
		_strategy = new CreditCardPayment;
		break;
	}
}

void PaymentProcessor::processPayment(float amount)
{
	_strategy->pay(amount);
}

PaymentProcessor::PaymentProcessor(PaymentType pt)
{
	_strategy = nullptr;
	setPaymentStrategy(pt);
}

PaymentProcessor::~PaymentProcessor()
{
	delete _strategy;
}