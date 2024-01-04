#pragma once
#include "PaymentStrategy.h"

class PaymentProcessor {
private:
    PaymentStrategy* paymentStrategy;

public:
    PaymentProcessor(PaymentStrategy* strategy) : paymentStrategy(strategy) {}

    void setPaymentStrategy(PaymentStrategy* strategy) {
        paymentStrategy = strategy;
    }

    void processPayment(float amount) {
        paymentStrategy->pay(amount);
    }
};