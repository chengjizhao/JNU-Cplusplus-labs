//定义一个类Book，包含私有成员变量title和author，以及公有成员函数void display()用于输出书籍信息。
//在main函数中使用new运算符动态创建一个Book对象，设置其标题和作者，然后调用display函数显示信息。
//使用delete运算符释放动态分配的内存，画UML图

#include<iostream>
#include<string>
using namespace std;

class Book 
{
    private:
    string title;
    string author;
    public:
    Book(){};
    Book(const string & x,const string & y):title(x),author(y){};
    ~Book(){};
    void display()
    {
        cout<<"The book's title is "<<title<<endl;
        cout<<"book's author is "<<author<<endl;
    }
};



int main ()
{
    Book* obj=new Book("homework","THR");
    obj->display();
    delete obj;
    return 0;


}
