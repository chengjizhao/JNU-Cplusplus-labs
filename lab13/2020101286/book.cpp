#include <iostream>
#include <vector>
#include <memory>

class Book {
public:
    std::string title;
    std::string author;
    Book(const std::string& t, const std::string& a) : title(t), author(a) {
        std::cout << "Book " << title << " by " << author << " is created" << std::endl;
    }
    ~Book() {
        std::cout << "Book " << title << " is destroyed" << std::endl;
    }
};

class Library {
public:
    std::vector<std::shared_ptr<Book>> books;

    void addBook(const std::shared_ptr<Book>& book) {
        books.push_back(book);
    }

    void removeBook(const std::shared_ptr<Book>& book) {
        for(auto it = books.begin(); it != books.end(); ++it) {
            if (*it == book) {
                books.erase(it);
                break;
            }
        }
    }

    void displayBooks() {
        std::cout << "Books in library: " << std::endl;
        for (const auto& book : books) {
            std::cout << "Title: " << book->title << ", Author: " << book->author << std::endl;
        }
    }
};

int main() {
    Library library;
    std::shared_ptr<Book> book1 = std::make_shared<Book>("The Great Gatsby", "F. Scott Fitzgerald");
    std::shared_ptr<Book> book2 = std::make_shared<Book>("To Kill a Mockingbird", "Harper Lee");
    library.addBook(book1);
    library.addBook(book2);

    library.displayBooks();

    library.removeBook(book1);
    library.displayBooks();

    return 0;
}