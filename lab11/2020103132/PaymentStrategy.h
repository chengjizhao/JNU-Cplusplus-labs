 
#pragma once  
#include <memory>  
  
class PaymentStrategy {  
public:  
    virtual ~PaymentStrategy() = default;  
    virtual float pay(float amount) = 0; // 声明支付接口，输入为要支付的金额，返回值为支付结果  
};