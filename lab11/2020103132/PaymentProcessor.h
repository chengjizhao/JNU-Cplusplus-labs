// PaymentProcessor.h  
#pragma once  
#include <memory>  
#include "PaymentStrategy.h"  
  
class PaymentProcessor {  
public:  
    void setPaymentStrategy(std::unique_ptr<PaymentStrategy> strategy) { paymentStrategy_ = std::move(strategy); } // 设置支付策略  
    void processPayment(float amount) { paymentStrategy_->pay(amount); } // 处理支付请求，调用当前支付策略的 pay 方法完成支付  
private:  
    std::unique_ptr<PaymentStrategy> paymentStrategy_; // 保存当前支付策略的成员变量，使用 unique_ptr 管理内存，防止内存泄露和野指针问题  
};