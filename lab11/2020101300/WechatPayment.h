#pragma once
#include "PaymentStrategy.h"

class WechatPayment : public PaymentStrategy {
public:
    virtual void pay(float amount) override {
        // 实现微信支付的逻辑
        std::cout << "Paid " << amount << " via Wechat." << std::endl;
    }
};