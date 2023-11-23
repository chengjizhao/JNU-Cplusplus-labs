# 四个模式

> 单例模式

```mermaid
classDiagram

class Singleton{
-instance: Singleton
	+getInstance():Singleton
}
Singleton o-- Singleton
```

应用场合：当需要在程序中的多个地方共享同一个实例时，比如配置管理器、日志记录器等。

> 工厂模式

```mermaid
classDiagram
class Product
class Factory{
+createProduct():Product
}
Product <-- Factory
```

应用场合：当一个类无法预知它必须创建的类的对象时，或者一个类希望由其子类来指定所创建的对象时，可以使用工厂模式。

> 桥接

```mermaid
classDiagram
class Abstraction{
-implementor
}
class Implementor{
+operationImp()
}
class ConcreteImplementorA{
-operationImp()
}
class ConcreteImplementorB{
-operationImp()
}
class RefindAbstraction{
-operation()
}
Abstraction o-- Implementor
Abstraction -- RefindAbstraction
Implementor <|--ConcreteImplementorA
Implementor <|--ConcreteImplementorB
```

应用场合：当一个类存在两个独立变化的维度，且需要在这两个维度上进行扩展时，可以使用桥接模式。

> 策略

```mermaid
classDiagram
class Context{
-stratery:stratery
+contextInterface()
}
class Stratery{
+algorithmInterface()
}
class concreteContext

class concreteStrateryA
class concreteStrateryB

 Context<-- concreteContext
Stratery <|.. concreteStrateryA
Stratery <|.. concreteStrateryB
Context o-- Stratery
```

应用场合： 策略模式定义了一族算法，将每个算法分别封装起来，并且使它们之间可以相互替换。
