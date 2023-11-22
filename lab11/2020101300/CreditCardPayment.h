#pragma once
#include "PaymentStrategy.h"

class CreditCardPayment : public PaymentStrategy {
public:
    virtual void pay(float amount) override {
        // 实现信用卡支付的逻辑
        std::cout << "Paid " << amount << " via Credit Card." << std::endl;
    }
};