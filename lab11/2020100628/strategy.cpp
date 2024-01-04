#include <iostream>
#include<vector>
#include <algorithm>

//Strategy interface
class PaymentStrategy {
public:
    virtual void pay(float amount) const = 0 ; 
};

//Concrete SortingStrategies
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(float amount) const override {
        std::cout << "信用卡支付" << amount << std::endl;
    }
};
class AlipayPayment : public PaymentStrategy {
public:
    void pay(float amount) const override {
        std::cout << "支付宝支付" << amount << std::endl;
    }
};
class WechatPayment : public PaymentStrategy {
public:
    void pay(float amount) const override {
        std::cout << "微信支付" << amount << std::endl;
    }
};
//Context
class PaymentProcessor {
private:
    PaymentStrategy* strategy;
public:
    PaymentProcessor(PaymentStrategy* strategy):strategy(strategy){}
    void setstrategy(PaymentStrategy* newStrategy){
        strategy = newStrategy;
    }
    void processPayment(float amount){
        strategy->pay(amount);
    }
};

int main()
{
    
    CreditCardPayment creditCardPayment;
    AlipayPayment alipayPayment;
    WechatPayment wechatPayment;

    PaymentProcessor paymentProcessor(&creditCardPayment);
    paymentProcessor.processPayment(0.01);

    paymentProcessor.setstrategy(&alipayPayment);
    paymentProcessor.processPayment(0.1);

    paymentProcessor.setstrategy(&wechatPayment);
    paymentProcessor.processPayment(1);
    return 0;
}

/*
创建一个接口 PaymentStrategy，它有一个方法 pay(amount: float) 用于进行支付。
创建三个实现了 PaymentStrategy 接口的类：CreditCardPayment, AlipayPayment, 和 WechatPayment。
创建一个 PaymentProcessor 类，它有一个成员变量 paymentStrategy，用于保存当前的支付策略。
PaymentProcessor 类有一个方法 processPayment(amount: float)，它调用当前支付策略的 pay 方法来完成支付。
*/