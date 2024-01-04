#include "PaymentStrategy.h"
#include <iostream>

PaymentStrategy::PaymentStrategy()
{}

AlipayPayment::AlipayPayment()
	: PaymentStrategy()
{}

WechatPayment::WechatPayment()
	: PaymentStrategy()
{}

CreditCardPayment::CreditCardPayment()
	: PaymentStrategy()
{}

void AlipayPayment::pay(float amount)
{
	std::cout << "Alipay payment: " << amount << std::endl;
}

void WechatPayment::pay(float amount)
{
	std::cout << "Wechat payment: " << amount << std::endl;
}

void CreditCardPayment::pay(float amount)
{
	std::cout << "CreditCard payment: " << amount << std::endl;
}