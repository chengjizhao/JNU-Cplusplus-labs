三种智能指针总结

## unique_ptr：

unique_ptr是独占式的，即完全拥有它所管理对象的所有权，不和其它的对象共享。unique_ptr禁用了拷贝构造和拷贝赋值构造，仅仅实现了移动构造和移动赋值构造，这也就使得它是独占式的。

使用方法：unique_ptr是C++11引入的轻量级智能指针，通过std::make_unique或std::move等方法进行创建和转移操作。

特点：unique_ptr独占所指向的对象，只有一个unique_ptr可以指向一个对象。当unique_ptr超出作用域，或者通过std::move转移所有权，它会自动释放所管理的对象。

使用场景：适合需要独占资源的情况，比如管理动态分配的内存或独立的对象。unique_ptr也可以作为函数的返回值

### shared_ptr：

使用方法：shared_ptr允许多个智能指针共享同一个对象，使用std::make_shared或std::shared_ptr构造函数创建。

特点：shared_ptr会记录有多少个shared_ptr所指向同一个对象，对象会在最后一个shared_ptr超出作用域时才会被自动释放。

使用场景：适合需要多个智能指针共享同一资源的情况，如资源管理、图的数据结构等。

## weak_ptr：

使用方法：weak_ptr是一种弱引用智能指针，不能通过weak_ptr直接访问对象，需要通过lock()方法获得shared_ptr才能使用。

特点：主要用于打破shared_ptr的循环引用，解决循环引用造成的内存泄漏问题。

使用场景：适合需要避免shared_ptr循环引用的情况，常用于配合shared_ptr一起使用。
