#### 2、解释的作用，它是如何与虚函数表关联的？

虚指针是一种可以指向不同类型对象的指针。当我们想创建一个基类，该基类可以用来创建不同类型的派生类时，以第一道考试题目为例，可以创建一个名为“Animal”的基类，然后创建名“Dog”、“Cat”的派生类。然后，可以创建一个指向“Animal”的虚指针，然后将其分配给指向“Dog”、“Cat”的指针。

当解引用虚指针时，将访问正确类型的对象，虚指针是使用虚函数表实现的。

虚函数表是一个函数指针表，与每个类相关联。类的虚函数表包含类中声明的每个虚函数的函数指针。当解引用虚指针时，将使用指针指向的对象的虚函数表来查找要调用的正确函数。



#### 如果一个类，包含虚函数，那么它的实例将包含什么额外的信息，以便正确调用虚函数？

当一个类包含虚函数时，它的实例将包含一个指向虚函数表的指针，这个指针用于在运行时查找并调用虚函数。。虚函数表 是一个函数指针表，每个类中的虚函数都有一个。当调用虚函数时，虚函数表 用于根据正在调用的对象的类型来查找要调用的正确函数。



#### 用UML图画出一种设计模式，它使用了虚函数来达成目标。
