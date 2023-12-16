#include <iostream>  
#include <memory>  
#include <vector>  
#include <string>  
  
class Book {  
public:  
    Book(const std::string& title, const std::string& author)  
        : title(title), author(author) {}  
  
    std::string getTitle() const { return title; }  
    std::string getAuthor() const { return author; }  
  
private:  
    std::string title;  
    std::string author;  
};  
  
class Library {  
public:  
    void addBook(std::shared_ptr<Book> bookPtr) {  
        books.push_back(bookPtr);  
    }  
  
    void removeBook(const std::string& title) {  
        /*for (auto it = books.begin(); it != books.end(); ++it) {  
            if (it->gettitle()== title) {  
                it->reset(); // 使用 reset() 手动删除 shared_ptr 所指向的对象  
                books.erase(it);  
                break;  
            }  
         } */
        if(books.size()>0)
        {
            for(int i=0;i<books.size();i++)
            {
            if(books[i]->getTitle()==title)
            {  
              books.erase(books.begin()+i);
            }
            }
        }
    }  
  
    void displayBooks() const {  
        for (const auto& book : books) {  
            std::cout << "Title: " << book->getTitle() << ", Author: " << book->getAuthor() << std::endl;  
        }  
    }  
  
private:  
    std::vector<std::shared_ptr<Book>> books; // 使用 shared_ptr 管理书籍对象  
};  
  
int main() {  
    Library library;  
    std::shared_ptr<Book> book1 = std::make_shared<Book>("Harry Potter", "J.K. Rowling");  
    std::shared_ptr<Book> book2 = std::make_shared<Book>("To Kill a Mockingbird", "Harper Lee");  
    library.addBook(book1);  
    library.addBook(book2);  
    library.displayBooks(); // 显示所有书籍  
    library.removeBook("Harry Potter"); // 删除书籍  
    library.displayBooks(); // 再次显示所有书籍，应该不包含 "Harry Potter"  
    return 0;  
}