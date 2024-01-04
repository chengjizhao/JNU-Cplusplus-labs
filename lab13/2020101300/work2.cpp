#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Book {
public:
    Book(std::string title, std::string author) : title(title), author(author) {}

    void displayInfo() const {
        std::cout << "Title: " << title << ", Author: " << author << std::endl;
    }

private:
    std::string title;
    std::string author;
};

class Library {
public:
    void addBook(std::shared_ptr<Book> book) {
        books.push_back(book);
        std::cout << "Book added to the library." << std::endl;
    }

    void removeBook(std::shared_ptr<Book> book) {
        auto it = std::remove_if(books.begin(), books.end(),
            [book](const auto& storedBook) {
                return storedBook == book;
            });

        if (it != books.end()) {
            books.erase(it, books.end());
            std::cout << "Book removed from the library." << std::endl;
        } else {
            std::cout << "Book not found in the library." << std::endl;
        }
    }

    void displayBooks() const {
        std::cout << "Books in the library:" << std::endl;
        for (const auto& book : books) {
            book->displayInfo();
        }
    }

private:
    std::vector<std::shared_ptr<Book>> books;
};

int main() {
    // Creating shared pointers for books
    auto book1 = std::make_shared<Book>("The Catcher in the Rye", "J.D. Salinger");
    auto book2 = std::make_shared<Book>("To Kill a Mockingbird", "Harper Lee");

    // Creating library and adding books
    Library library;
    library.addBook(book1);
    library.addBook(book2);

    // Displaying books in the library
    library.displayBooks();

    // Removing a book from the library
    library.removeBook(book1);

    // Displaying updated list of books in the library
    library.displayBooks();

    // The program will automatically release memory when shared_ptr objects go out of scope

    return 0;
}