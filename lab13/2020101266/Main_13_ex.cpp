#include <iostream>  
#include <vector>  
#include <memory>  
#include <string>  
#include <algorithm>  

class Book {
public:
    Book(const std::string& name, const std::string& author)
        : name_(name), author_(author) {
        std::cout << "Book created: " << name << " by " << author << std::endl;
    }
    ~Book() {
        std::cout << "Book destroyed: " << name_ << " by " << author_ << std::endl;
    }
    void printInfo() const {
        std::cout << "Book: " << name_ << " by " << author_ << std::endl;
    }
private:
    std::string name_;
    std::string author_;
};

class Library {
public:
    void addBook(const std::shared_ptr<Book>& book) {
        books_.push_back(book);
        std::cout << "Book added to the library." << std::endl;
    }
    void removeBook(const std::string& name) {
        auto it = std::remove_if(books_.begin(), books_.end(),
            [&name](const std::shared_ptr<Book>& book) {
                return book->name_ == name;
            });
        books_.erase(it, books_.end());
        std::cout << "Book removed from the library." << std::endl;
    }
    void showBooks() const {
        for (const auto& book : books_) {
            book->printInfo();
        }
    }
private:
    std::vector<std::shared_ptr<Book>> books_;
};

int main() {
    std::shared_ptr<Library> lib = std::make_shared<Library>();
    std::shared_ptr<Book> book1 = std::make_shared<Book>("C++ Primer", "Stanley B. Lippman");
    std::shared_ptr<Book> book2 = std::make_shared<Book>("Effective C++", "Scott Meyers");
    lib->addBook(book1);
    lib->addBook(book2);
    lib->showBooks();
    lib->removeBook("C++ Primer");
    lib->showBooks();
    return 0;
}