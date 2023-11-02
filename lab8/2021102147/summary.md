# C++ 类的继承及多态

## 继承
为了最大限度复用代码，可以通过原有的一个类扩展出一个新的类，新的类叫做原来的类的子类，继承了原来类的成员和方法。根据不同的
继承方式，成员、方法在子类中的可访问性也不一样。

## 多态
有时候，我们希望通过基类的指针或者变量来处理子类的对象，这就是类的多态性。例如
```cpp
double getIncome(Person &p)
{
	return p.getTotalIncome() * (1 - p.getTaxRate());
}

Teacher t;
double income = getIncome(t);
```

在上面的例子中，Person是一个基类，由它可以派生出多个子类，比如Teacher、Driver等。不同职业的人有不同的总收入，可能有不同的
税率。因此，要计算一个人的实际收入，需要得到这个人对应职业的总收入和税率。而我们的getIncome函数并不知道我们传入的人的职业。如果
按照一般的处理方法，会调用`Person::getIncome`和`Person::getTaxRate`而不是`Teacher::getIncome`和`Teacher::getTaxRate`，这显然
会导致出错。为了处理这种情况，C++有一种特性叫做虚函数。在定义基类成员方法时，使用virtual关键字修饰函数。
```cpp
class Person
{
public:
	virtual double getTotalIncome();
	virtual double getTaxRate();
	...
};
```
在子类中，当`getTotalIncome`和`getTaxRate`被重新定义时
```cpp
class Teacher
{
public:
	// virtual可不写，但一般写上方便辨认
	virtual double getTotalIncome();
	virtual double getTaxRate();
	...
}
```
会覆盖掉父类的函数签名相同的方法，并！且！当我们使用Person类的指针或引用来调用Teacher对象的方法时，会调用Teacher类的方法而不是
Person类的方法。

另外有一种特殊的虚函数叫做纯虚函数，这种虚函数没有定义。包含纯虚函数的类叫做抽象类。抽象类不能
被实例化，只能被子类继承，类似模板。

