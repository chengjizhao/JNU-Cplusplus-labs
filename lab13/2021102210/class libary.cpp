#include<iostream>
#include<memory>
#include<string>
#include<vector>
using namespace std ;

class Libary ;
class Book;

class Book
{
    public:
    string name;
    string writer;
    Book(string a, string b)
    {
        name=a;
        writer=b;
    }
    void show()
    {
        cout << name << " writen by " << writer << endl ;
    }
};

class Libary
{
    public:
    vector<shared_ptr<Book>> ap ;
    void deleteall()
    {
        ap.clear();
        cout << "all the books have been deleted " << endl ;
    }
    void addbook(shared_ptr<Book> bp)
    {
        ap.push_back(bp);
        cout << "there is " << ap.size() << " book now" << endl ;
    }
    void checkall()
    {
        if(ap.size()>0)
        {
            for(int i=0;i<ap.size();i++)
            {
            ap[i]->show();
            }
        }
        else 
        {
            cout << "there is no book " << endl ;
        }
    }
    void deleteone(int a)
    {
        ap[a-1]->show();
        ap.erase(ap.begin()+(a-1));
        cout << "this book has been deleted " << endl ;
    }
};



int main()
{
    Libary libary ;
    shared_ptr<Book> a1(new Book("cpp","a"));
    shared_ptr<Book> a2(new Book("c++","b"));
    shared_ptr<Book> a3(new Book("cxx","c"));
    libary.addbook(a1);
    libary.addbook(a2);
    libary.addbook(a3);
    libary.checkall();
    libary.deleteone(2);
    libary.checkall();
    libary.deleteall();
    libary.checkall();
}