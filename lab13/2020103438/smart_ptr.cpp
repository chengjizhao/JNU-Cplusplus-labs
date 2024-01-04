题目3： 考虑一个简单的图书馆管理系统，其中有Book和Library两个类。Library类包含一个保存书籍的容器，使用智能指针来管理书籍对象。使用shared_ptr来管理Book，并在需要时在Library中添加或删除书籍。

    编写程序，模拟图书馆管理系统的基本功能，包括添加书籍、删除书籍和显示图书馆中所有书籍的功能。

        要求
            Book类包含书籍的名称和作者等基本信息。
                Library类包含一个vector或其他容器，用于存储shared_ptr<Book>。 实现向图书馆添加书籍、从图书馆删除书籍以及显示图书馆中所有书籍的功能。
                    使用智能指针确保在不再需要书籍时能够正确释放内存。
                        在程序结束时输出相关信息，观察对象的销毁顺序。

    class Address;
class Person
{
public:

    ~Person()
    {
        cout << "destruct Person" << endl;
    }
    Person(string name,int age)
    {
        this->name = name;
        this->age = age;
        cout << "create Person" << endl;
    }

    string name;
    int age;
    shared_ptr<Address> sp;
};
class Address
{
public:
    ~Address()
    {
        cout << "destruct Address" << endl;
    }
    Address(string city,string street)
    {
        this->city = city;
        this->street = street;
        cout << "creater Address" << endl;
    }
    string city;
    string street;
    weak_ptr<Person> wp ;
};
int main()
{
    shared_ptr<Person> p1 = make_shared<Person>("chen",22);
    shared_ptr<Address> a1 = make_shared<Address>("珠海","暨南大学");
    p1->sp = a1;
    a1->wp = p1;
}