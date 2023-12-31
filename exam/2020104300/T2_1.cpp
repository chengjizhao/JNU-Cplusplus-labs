//虚函数表是一个静态的数据结构，通常位于程序的数据段，由编译器生成，每个具有虚函数的类都有一个与之关联的虚函数表。虚函数表中的每个条目都是一个指向虚函数实现的指针。派生类可以继承、重写或添加虚函数。当派生类继承基类的虚函数时，它们在虚函数表中具有相同的偏移量。当派生类重写虚函数时，它会在其虚函数表中用新的函数实现替换基类函数的指针。当派生类添加新的虚函数时，这些函数将被添加到虚函数表的末尾。
//虚继承底层实现原理与编译器相关，一般通过虚基类指针和虚基类表实现，每个虚继承的子类都有一个虚基类指针和虚基类表（虚基类依旧会在子类里面存在拷贝，只是仅仅最多存在一份而已，并不是不在子类里面了）；当虚继承的子类被当做父类继承时，虚基类指针也会被继承。
//当一个类含有至少一个虚函数时，编译器会为这个类创建一个虚函数表，并将类的每个实例的第一个字节地址设置为该虚函数表的地址。通过这个地址，我们可以访问虚函数表中的内容，也就是虚函数的地址。
//通过编译器的编译，基类和派生类的代码中都将有自己的虛函数表，为这些类创建实例化对象时，会在实例化的对象中插入一个指向对应的虚函数表的指针， 该指针通常在存放在对象的开头区域。而虚函数表可以看做就是一个其数据类型为函数指针的静态数组, 每一个函数指针指向对应类中的一个虚函数。
