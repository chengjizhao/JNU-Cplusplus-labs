#include<iostream>
#include<vector>
#include<memory>
#include<string>
using namespace std;
class Book;
class Library;
class Book
{
    public:
    Book(const string&bookname_,const string&author_):bookname(bookname_),author(author_){}
    string getbookname()const{return bookname;};
    string getauthor()const{return author;};
    private:
    string bookname;
    string author;
};
class Library
{
    public:
    vector<shared_ptr<Book>>books;
    void addbook(const string& bookname, const string& author);
    void deletebook(const string& bookename);
    void display()const;
};
void Library::addbook(const string& bookname, const string& author) {
    books.push_back(make_shared<Book>(bookname,author));
}
void Library::deletebook(const string& bookname) {
    for(auto it = books.begin();it!=books.end();++it)
    {
        if(it->get()->getbookname()== bookname)
        {
            books.erase(it);
            return;
        }
    }
}
void Library::display()const{
    for(const auto&book:books)
    {
        cout<<"title:"<<book->getbookname()<<" "<<"author:"<<book->getauthor()<<endl;
    }
}
int main()
{
    Library library;
    library.addbook("book1","author1");
    library.addbook("book2","author2");
    library.display(); // Display all books in the library  
    library.deletebook("Book1"); // Remove a book from the library  
    library.display(); // Display all books in the library again  
    return 0;
}