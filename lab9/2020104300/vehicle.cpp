//虚基类（virtual base class）在C++中主要用于解决多重继承带来的"多份数据"问题。在多重继承的情况下，如果多个基类有相同的成员，那么这个成员在派生类中就会出现多份，这就是所谓的多份数据问题。

#include <iostream>  
  
class Base1 {  
public:  
    int data;  
};  
  
class Base2 {  
public:  
    int data;  
};  
  
class Derived : public Base1, public Base2 {  
public:  
    void printData() {  
        std::cout << "Derived data: " << data << std::endl;  
    }  
};  
  
int main() {  
    Derived d;  
    d.data = 10; // Derived类中的data成员被赋值  
    d.printData(); // 输出 "Derived data: 10"  
    return 0;  
}
//在上述代码中，如果我们没有使用虚基类，那么在Derived类中就会存在两个data成员，分别来自Base1和Base2。这就导致了所谓的"多份数据"问题。

//然而，如果我们使用虚基类，这个问题就可以得到解决。只需要将Base1和Base2的基类改为虚基类即可。下面是修改后的代码：

#include <iostream>  
  
class Base1 {  
public:  
    virtual int data; // 虚基类成员  
};  
  
class Base2 {  
public:  
    virtual int data; // 虚基类成员  
};  
  
class Derived : public Base1, public Base2 {  
public:  
    void printData() {  
        std::cout << "Derived data: " << data << std::endl; // 这里只需要一个data成员，不再出现"多份数据"问题。  
    }  
};  
  
int main() {  
    Derived d;  
    d.data = 10; // Derived类中的data成员被赋值，这个成员来自于Base1或Base2，但C++会根据最后的派生类来确定具体是哪个基类的成员。因此，在Derived类中只有一个data成员。这就是虚基类解决"多份数据"问题的关键所在。  
    d.printData(); // 输出 "Derived data: 10"  
    return 0;  
}
//这样，即使在Derived类中只有一个data成员，我们也无需担心它可能来自哪个基类。C++会根据最后的派生类来确定具体是哪个基类的成员。这就是虚基类解决"多份数据"问题的关键所在。
