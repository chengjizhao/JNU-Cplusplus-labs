#include <iostream>  
#include <vector>  
#include <memory>  
  
class Book {  
public:  
    Book(const std::string& name, const std::string& author)  
        : name(name), author(author) {}  
  
    std::string getName() const {  
        return name;  
    }  
  
    std::string getAuthor() const {  
        return author;  
    }  
  
private:  
    std::string name;  
    std::string author;  
};  
  
class Library {  
public:  
    void addBook(const Book& book) {  
        books.push_back(std::make_shared<Book>(book));  
    }  
  
    void removeBook(const std::string& bookName) {  
        for (auto it = books.begin(); it != books.end(); ++it) {  
            if (it->get()->getName() == bookName) {  
                books.erase(it);  
                break;  
            }  
        }  
    }  
  
    void displayBooks() const {  
        for (const auto& book : books) {  
            std::cout << "Name: " << book->getName() << ", Author: " << book->getAuthor() << std::endl;  
        }  
    }  
  
private:  
    std::vector<std::shared_ptr<Book>> books;  
};  
  
int main() {  
    Library library;  
    library.addBook(Book("Book1", "Author1"));  
    library.addBook(Book("Book2", "Author2"));  
    library.addBook(Book("Book3", "Author3"));  
    library.displayBooks(); // 显示所有书籍  
    library.removeBook("Book2"); // 删除一本书籍  
    library.displayBooks(); // 显示所有书籍，应不再显示被删除的书籍  
    std::cout << "Library is empty: " << (library.books.empty() ? "true" : "false") << std::endl; // 输出图书馆是否为空，应为false，因为还有书籍存在  
    return 0;  
}
