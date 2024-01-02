#pragma once  
#include "PaymentStrategy.h"  
#include <string>  
  
class CreditCardPayment : public PaymentStrategy 
{  
public:  
    CreditCardPayment(std::string cardNumber, std::string cvv, std::string expirationDate) : cardNumber_(cardNumber), cvv_(cvv), expirationDate_(expirationDate) {}  
    float pay(float amount) override 
    {  
        return amount; // 假设信用卡支付成功，返回支付金额  
    }  
private:  
    std::string cardNumber_;  
    std::string cvv_;  
    std::string expirationDate_;  
};

class AliPayment : public PaymentStrategy 
{  
public:  
    AliPayment(std::string cardNumber, std::string cvv, std::string expirationDate) : cardNumber_(cardNumber), cvv_(cvv), expirationDate_(expirationDate) {}  
    float pay(float amount) override 
    {  
        return amount; // 假设信用卡支付成功，返回支付金额  
    }  
private:  
    std::string cardNumber_;  
    std::string cvv_;  
    std::string expirationDate_;  
};

class WechatPayment : public PaymentStrategy 
{  
public:  
    WechatPayment(std::string cardNumber, std::string cvv, std::string expirationDate) : cardNumber_(cardNumber), cvv_(cvv), expirationDate_(expirationDate) {}  
    float pay(float amount) override 
    {  
        return amount; // 假设信用卡支付成功，返回支付金额  
    }  
private:  
    std::string cardNumber_;  
    std::string cvv_;  
    std::string expirationDate_;  
};


