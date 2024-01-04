#pragma once
#include "PaymentStrategy.h"

class AlipayPayment : public PaymentStrategy {
public:
    virtual void pay(float amount) override {
        // 实现支付宝支付的逻辑
        std::cout << "Paid " << amount << " via Alipay." << std::endl;
    }
};