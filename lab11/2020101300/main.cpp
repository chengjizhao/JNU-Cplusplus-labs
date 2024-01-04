#include <iostream>
#include "CreditCardPayment.h"
#include "AlipayPayment.h"
#include "WechatPayment.h"
#include "PaymentProcessor.h"

int main() {
    // 创建支付策略对象
    CreditCardPayment creditCardPayment;
    AlipayPayment alipayPayment;
    WechatPayment wechatPayment;

    // 创建支付处理器并设置初始支付策略为信用卡支付
    PaymentProcessor paymentProcessor(&creditCardPayment);

    // 进行支付
    paymentProcessor.processPayment(100.0f);

    // 切换支付策略为支付宝支付
    paymentProcessor.setPaymentStrategy(&alipayPayment);
    paymentProcessor.processPayment(50.0f);

    // 切换支付策略为微信支付
    paymentProcessor.setPaymentStrategy(&wechatPayment);
    paymentProcessor.processPayment(30.0f);

    return 0;
}