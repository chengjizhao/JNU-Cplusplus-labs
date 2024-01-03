#include <iostream>  
#include <vector>  
#include <memory>  
#include <string>  
  
class Book {  
public:  
    Book(const std::string& name, const std::string& author)   
        : name_(name), author_(author) {  
        std::cout << "Book created: " << name << " by " << author << std::endl;  
    }  
  
    ~Book() {  
        std::cout << "Book destroyed: " << name_ << " by " << author_ << std::endl;  
    }  
  
    const std::string& getName() const { return name_; }  
    const std::string& getAuthor() const { return author_; }  
  
private:  
    std::string name_;  
    std::string author_;  
};  
  
class Library {  
public:  
    void addBook(std::shared_ptr<Book> book) {  
        books_.push_back(book);  
        std::cout << "Book added to the library." << std::endl;  
    }  
  
    void removeBook(const std::string& name) {  
        for (auto it = books_.begin(); it != books_.end(); ++it) {  
            if ((*it)->getName() == name) {  
                books_.erase(it);  
                std::cout << "Book removed from the library." << std::endl;  
                return;  
            }  
        }  
        std::cout << "Book not found in the library." << std::endl;  
    }  
  
    void showBooks() const {  
        for (const auto& book : books_) {  
            std::cout << book->getName() << " by " << book->getAuthor() << std::endl;  
        }  
    }  
  
private:  
    std::vector<std::shared_ptr<Book>> books_;  
};  
  
int main() {  
    std::shared_ptr<Library> lib = std::make_shared<Library>();  
    lib->addBook(std::make_shared<Book>("The Great Gatsby", "F. Scott Fitzgerald"));  
    lib->addBook(std::make_shared<Book>("To Kill a Mockingbird", "Harper Lee"));  
    lib->showBooks();  
    lib->removeBook("The Great Gatsby");  
    lib->showBooks();  
    return 0;  
}