#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>

class Book {
public:
    std::string title;
    std::string author;

    Book(const std::string& t, const std::string& a) : title(t), author(a) {
        std::cout << "Book " << title << " by " << author << " created" << std::endl;
    }

    ~Book() {
        std::cout << "Book " << title << " by " << author << " destroyed" << std::endl;
    }
};

class Library {
private:
    std::vector<std::shared_ptr<Book>> books;

public:
    void addBook(const std::string& title, const std::string& author) {
        books.push_back(std::make_shared<Book>(title, author));
    }

    void removeBook(const std::string& title) {
        auto it = std::remove_if(books.begin(), books.end(),
            [&](const std::shared_ptr<Book>& b) { return b->title == title; });
        books.erase(it, books.end());
    }

    void displayBooks() {
        std::cout << "Books in library:" << std::endl;
        for (const auto& b : books) {
            std::cout << b->title << " by " << b->author << std::endl;
        }
    }
};

int main() {
    Library library;
    library.addBook("The Catcher in the Rye", "J.D. Salinger");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.addBook("1984", "George Orwell");
    library.displayBooks();

    library.removeBook("To Kill a Mockingbird");
    library.displayBooks();

    return 0;
}