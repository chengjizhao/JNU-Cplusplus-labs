#include <iostream>

// PaymentStrategy�ӿ�
class PaymentStrategy {
public:
    virtual void pay(float amount) = 0;
};

// CreditCardPayment��
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "Credit card payment: $" << amount << std::endl;
        // ʵ�����ÿ�֧���ľ����߼�
    }
};

// AlipayPayment��
class AlipayPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "Alipay payment: $" << amount << std::endl;
        // ʵ��֧����֧���ľ����߼�
    }
};

// WechatPayment��
class WechatPayment : public PaymentStrategy {
public:
    void pay(float amount) override {
        std::cout << "WeChat payment: $" << amount << std::endl;
        // ʵ��΢��֧���ľ����߼�
    }
};

// PaymentProcessor��
class PaymentProcessor {
private:
    PaymentStrategy* paymentStrategy;

public:
    void setPaymentStrategy(PaymentStrategy* strategy) {
        paymentStrategy = strategy;
    }

    void processPayment(float amount) {
        if (paymentStrategy != nullptr) {
            paymentStrategy->pay(amount);
        }
    }
};

int main() {
    // ����֧������
    PaymentStrategy* creditCardPayment = new CreditCardPayment();
    PaymentStrategy* alipayPayment = new AlipayPayment();
    PaymentStrategy* wechatPayment = new WechatPayment();

    // ����֧��������
    PaymentProcessor paymentProcessor;

    // ʹ�ò�ͬ��֧�����Խ���֧��
    paymentProcessor.setPaymentStrategy(creditCardPayment);
    paymentProcessor.processPayment(100.0f);

    paymentProcessor.setPaymentStrategy(alipayPayment);
    paymentProcessor.processPayment(200.0f);

    paymentProcessor.setPaymentStrategy(wechatPayment);
    paymentProcessor.processPayment(300.0f);

    // �ͷ��ڴ�
    delete creditCardPayment;
    delete alipayPayment;
    delete wechatPayment;

    return 0;
}