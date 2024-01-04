
# unique_ptr
## 使用方法：
创建：
```C++
unique_ptr<int> up = make_unique<int>(100)
unique_ptr<int> up(new int(10));
```
转移所有权：由于独占所有权，不能复制；可以通过 std::move 转移所有权。

释放资源：当 std::unique_ptr 离开作用域或调用 reset() 时，会自动释放资源。
## 特点：
独占所有权：一个 std::unique_ptr 实例是唯一拥有其所指向对象的智能指针。

性能和内存效率：由于只有一个所有者，不需要引用计数，因此更加轻量级。

安全性：能够避免常见的内存管理问题，如悬挂指针和多次释放。
## 使用场景：
当需要确保资源的独占所有权时。

当资源需要动态分配，并且有清晰的所有者时。

在容器或类成员中，以确保资源的生命周期。
# shared_ptr
## 使用方法：
创建：
```C++
shared_ptr<int> p1 = make_shared<int>(99)//也额可以使用{}方式
shared_ptr<int> p(new int(100));
```
共享所有权：多个 std::shared_ptr 可以指向同一个对象。
解引用和成员访问：与原始指针类似。

重置和释放：当所有 std::shared_ptr 超出范围或被重置时，资源会在引用计数减少到零时被释放,使用`ptr.reset()`重置
## 特点：
共享所有权：允许多个指针共享对同一资源的访问。

引用计数：内部维护一个引用计数，跟踪有多少个 std::shared_ptr 指向同一个对象。

性能开销：引用计数可能带来额外的性能开销。

循环引用问题：可能导致循环引用和内存泄漏，需要使用 std::weak_ptr 解决。
## 使用场景： 
在需要多个所有者共享资源的情况下。

当对象的生命周期不确定时或需要在多个地方访问相同对象时。

与 std::weak_ptr 一起使用，以避免循环引用。
# weak_ptr
## 使用方法：
创建：
```C++
std::shared_ptr<int> sharedPtr = std::make_shared<int>(42);
std::weak_ptr<int> weakPtr = sharedPtr;

```
检查对象：使用 lock() 方法尝试获得一个 std::shared_ptr，如果对象仍然存在，则返回有效的 std::shared_ptr；否则返回空。
## 特点：
弱引用：不会增加对象的引用计数，因此不会延长对象的生命周期。

解决循环引用：主要用于解决 std::shared_ptr 可能导致的循环引用问题。

安全：提供了一种安全的方式来访问可能已经被销毁的对象。
## 使用场景：
当需要避免循环引用时，与 std::shared_ptr 一起使用。

用于回调和事件处理，以避免在 std::shared_ptr 之间创建强引用。

在容器、观察者模式和其他可能导致循环引用的场景中使用。