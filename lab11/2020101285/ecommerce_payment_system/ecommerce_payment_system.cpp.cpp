#include "ecommerce_payment_system.h"
int main() {
    // 创建不同的支付策略
    PaymentStrategy* creditCardStrategy = new CreditCardPayment();
    PaymentStrategy* alipayStrategy = new AlipayPayment();
    PaymentStrategy* wechatStrategy = new WechatPayment();

    // 创建 PaymentProcessor 实例，并设置默认支付策略为信用卡支付
    PaymentProcessor paymentProcessor(creditCardStrategy);

    // 演示使用不同的支付策略进行支付
    paymentProcessor.processPayment(100.0f);  // 使用信用卡支付

    // 切换支付策略为支付宝支付
    paymentProcessor.setPaymentStrategy(alipayStrategy);
    paymentProcessor.processPayment(50.0f);   // 使用支付宝支付

    // 切换支付策略为微信支付
    paymentProcessor.setPaymentStrategy(wechatStrategy);
    paymentProcessor.processPayment(30.0f);   // 使用微信支付

    // 释放内存
    delete creditCardStrategy;
    delete alipayStrategy;
    delete wechatStrategy;

    return 0;
}
