#include <iostream>  
#include <memory>  
#include <vector>  
#include <string>  
  
class Book 
{  
public:  
    Book(const std::string& name, const std::string& author)  
        : name_(name), author_(author) {}  
  
    void PrintInfo() const 
    {  
        std::cout << "Book: " << name_ << " by " << author_ << std::endl;  
    }  
  
private:  
    std::string name_;  
    std::string author_;  
};  
  
class Library 
{  
public:  
    void AddBook(std::shared_ptr<Book> book) 
    {  
        books_.push_back(book);  
    }  
  
    void RemoveBook(const std::string& bookName) 
    {  
        for (auto it = books_.begin(); it != books_.end(); ++it) 
        {  
            if ((*it)->name_ == bookName) 
            {  
                books_.erase(it);  
                return; // Assuming book names are unique  
            }  
        }  
        std::cout << "Book not found in the library." << std::endl;  
    }  
  
    void DisplayBooks() const 
    {  
        for (const auto& book : books_) 
        {  
            book->PrintInfo();  
        }  
    }  
  
private:  
    std::vector<std::shared_ptr<Book>> books_;  
};  
  
int main() 
{  
    Library library;   
    library.AddBook(std::make_shared<Book>("The Great Gatsby", "F. Scott Fitzgerald"));  
    library.AddBook(std::make_shared<Book>("To Kill a Mockingbird", "Harper Lee"));  
    library.AddBook(std::make_shared<Book>("1984", "George Orwell"));  
    std::cout << "Books in the library:" << std::endl;  
    library.DisplayBooks();  
    library.RemoveBook("To Kill a Mockingbird");  
    std::cout << "\nBooks after removal:" << std::endl;  
    library.DisplayBooks();  
    return 0;  
}