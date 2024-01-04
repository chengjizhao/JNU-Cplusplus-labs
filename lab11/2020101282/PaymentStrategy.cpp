# 定义支付策略接口
class PaymentStrategy:
    def pay(self, amount: float):
        pass

# 实现信用卡支付策略
class CreditCardPayment(PaymentStrategy):
    def pay(self, amount: float):
        print(f"Paid {amount} via Credit Card")

# 实现支付宝支付策略
class AlipayPayment(PaymentStrategy):
    def pay(self, amount: float):
        print(f"Paid {amount} via Alipay")

# 实现微信支付策略
class WechatPayment(PaymentStrategy):
    def pay(self, amount: float):
        print(f"Paid {amount} via WeChat")

# 定义支付处理器类
class PaymentProcessor:
    def __init__(self, payment_strategy: PaymentStrategy):
        self.payment_strategy = payment_strategy

    def process_payment(self, amount: float):
        self.payment_strategy.pay(amount)

# 客户端代码示例
if __name__ == "__main__":
    # 创建不同的支付策略
    credit_card_strategy = CreditCardPayment()
    alipay_strategy = AlipayPayment()
    wechat_strategy = WechatPayment()

    # 创建支付处理器并设置支付策略
    payment_processor = PaymentProcessor(credit_card_strategy)

    # 进行支付
    payment_processor.process_payment(100.0)

    # 切换支付策略
    payment_processor.payment_strategy = alipay_strategy

    # 再次进行支付
    payment_processor.process_payment(50.0)

    # 切换支付策略
    payment_processor.payment_strategy = wechat_strategy

    # 再次进行支付
    payment_processor.process_payment(30.0)
