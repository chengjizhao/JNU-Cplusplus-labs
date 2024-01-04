#pragma once

class PaymentStrategy {
public:
    virtual void pay(float amount) = 0;
};