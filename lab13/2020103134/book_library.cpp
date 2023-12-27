#include<iostream>
#include<memory>
#include<string>
#include<vector>
using namespace std;
class Book{
    private:
    string title;
    string author;
    public:
    Book(const string &title , const string &author):title(title),author(author){}
    string get_title()const{return title;}
    string get_author()const{return author;}
};
class Library{
    private:
    vector<shared_ptr<Book>> books;
    public:
    void add_book(const shared_ptr<Book> &book){books.push_back(book);}
    void delete_book(const shared_ptr<Book> &book){
        for(auto it=books.begin();it!=books.end();it++){
            if(*it==book)
            {
                books.erase(it);
                break;
            }
        }
    }
    void show_book()const{
        for(const auto &book:books){
            cout<<"名称："<<book->get_title()<<",作者："<<book->get_author()<<endl;
        }
    }
};
int main(){
    Library library;
    shared_ptr<Book> book1=make_shared<Book>("自动控制原理", "王建辉");
    shared_ptr<Book> book2=make_shared<Book>("现代控制原理", "刘豹");
    library.add_book(book1);
    library.add_book(book2);
    library.show_book();
    library.delete_book(book1);
    library.show_book();
    return 0;
}