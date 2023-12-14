#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> // Include the algorithm header for std::remove_if
#include <string>

class Book {
public:
    Book(const std::string& title, const std::string& author)
        : title(title), author(author) {}

    const std::string& getTitle() const {
        return title;
    }

    void displayInfo() const {
        std::cout << "Title: " << title << ", Author: " << author << std::endl;
    }

private:
    std::string title;
    std::string author;
};

class Library {
public:
    void addBook(const std::string& title, const std::string& author) {
        auto newBook = std::make_shared<Book>(title, author);
        books.push_back(newBook);
        std::cout << "Book added to the library: " << title << std::endl;
    }

    void removeBook(const std::string& title) {
        auto it = std::remove_if(books.begin(), books.end(),
                                 [title](const std::shared_ptr<Book>& book) {
                                     return book->getTitle() == title;
                                 });

        if (it != books.end()) {
            books.erase(it, books.end());
            std::cout << "Book removed from the library: " << title << std::endl;
        } else {
            std::cout << "Book not found in the library: " << title << std::endl;
        }
    }

    void displayBooks() const {
        if (books.empty()) {
            std::cout << "The library is empty." << std::endl;
        } else {
            std::cout << "Books in the library:" << std::endl;
            for (const auto& book : books) {
                book->displayInfo();
            }
        }
    }

    ~Library() {
        std::cout << "Library is closing. Cleaning up..." << std::endl;
    }

private:
    std::vector<std::shared_ptr<Book>> books;
};

int main() {
    Library library;

    // Adding books to the library
    library.addBook("The Catcher in the Rye", "J.D. Salinger");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.addBook("1984", "George Orwell");

    // Displaying books in the library
    library.displayBooks();

    // Removing a book from the library
    library.removeBook("To Kill a Mockingbird");

    // Displaying books after removal
    library.displayBooks();

    // The Library destructor will be called when 'library' goes out of scope
    return 0;
}

