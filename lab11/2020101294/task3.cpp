#include <iostream>

// PaymentStrategy �ӿ�
class PaymentStrategy {
public:
    virtual void pay(float amount) = 0;
};

// CreditCardPayment ��ʵ�� PaymentStrategy �ӿ�
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "Paid " << amount << " via Credit Card." << std::endl;
    }
};

// AlipayPayment ��ʵ�� PaymentStrategy �ӿ�
class AlipayPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "Paid " << amount << " via Alipay." << std::endl;
    }
};

// WechatPayment ��ʵ�� PaymentStrategy �ӿ�
class WechatPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "Paid " << amount << " via Wechat." << std::endl;
    }
};

// PaymentProcessor ��
class PaymentProcessor {
private:
    PaymentStrategy* paymentStrategy;

public:
    void setPaymentStrategy(PaymentStrategy* strategy) {
        paymentStrategy = strategy;
    }

    void processPayment(float amount) {
        if (paymentStrategy) {
            paymentStrategy->pay(amount);
        } else {
            std::cout << "No payment strategy set." << std::endl;
        }
    }
};

// �ͻ��˴���ʾ��
int main() {
    PaymentProcessor processor;

    CreditCardPayment creditCard;
    AlipayPayment alipay;
    WechatPayment wechat;

    // ʹ�� CreditCardPayment ����֧��
    processor.setPaymentStrategy(&creditCard);
    processor.processPayment(100.0);

    // ʹ�� AlipayPayment ����֧��
    processor.setPaymentStrategy(&alipay);
    processor.processPayment(50.0);

    // ʹ�� WechatPayment ����֧��
    processor.setPaymentStrategy(&wechat);
    processor.processPayment(30.0);

    return 0;
}