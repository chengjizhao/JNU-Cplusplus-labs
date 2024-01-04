#include <iostream>

#include "PaymentProcessor.h"
#include "PaymentStrategy.h"

int main(int argc, const char* argv[])
{
	PaymentProcessor processor(Alipay);
	processor.processPayment(100.5);

	processor.setPaymentStrategy(Wechat);
	processor.processPayment(200.5);

	processor.setPaymentStrategy(CreditCard);
	processor.processPayment(300.5);
	return 0;
}