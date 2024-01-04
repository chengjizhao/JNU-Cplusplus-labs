#include <iostream>
#include <memory>
#include <vector>
using namespace std;
class Book
{
public:
    friend class Library;
    Book(string name, string author)
    {
        this->author = author;
        this->name = name;
    }
    ~Book()
    {
        cout << "distruct Book" << endl;
    }

private:
    string name;
    string author;
};
class Library
{
public:
    void add_book(string name, string author)
    {
        shared_ptr<Book> bb = make_shared<Book>( name,  author);
        v.push_back(bb);
        cout <<"添加成功" << endl;
    }
    void delete_book(string name)
    {
        int ret =0;
        for (vector<shared_ptr<Book>>::iterator it = v.begin(); it != v.end(); it++)
        {
            if ((*it)->name == name)
            {
                v.erase(it);
                cout <<"删除成功" << endl;
                ret++;
            }
        }
        if(ret==0)
            cout <<"未找到对应的书籍" << endl;
    }
    void show_book()
    {          
        cout << "书名:" <<  "\t" << "作者:" << endl;
        for (vector<shared_ptr<Book>>::iterator it = v.begin(); it != v.end(); it++)
        {
        cout << (*it)->name <<  "\t"  <<(*it)->author<< endl;
        }
    }

private:
    vector<shared_ptr<Book>> v;
};

int main()
{
    Library JNU;
    JNU.add_book("三国","Luo");
    JNU.add_book("水浒","Shi");
    cout << endl;

    JNU.show_book();
    cout << endl;

    JNU.delete_book("西游");
    cout << endl;

    JNU.delete_book("三国");
    cout << endl;

    JNU.show_book();
}