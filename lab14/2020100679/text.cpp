#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

class Book {
public:
    Book(const std::string& title, const std::string& author) : title(title), author(author) {
        std::cout << "Creating Book: " << title << std::endl;
    }

    ~Book() {
        std::cout << "Destroying Book: " << title << std::endl;
    }

    std::string getTitle() const {
        return title;
    }

    std::string getAuthor() const {
        return author;
    }

private:
    std::string title;
    std::string author;
};

class Library {
public:
    void addBook(const std::string& title, const std::string& author) {
        std::shared_ptr<Book> newBook = std::make_shared<Book>(title, author);
        books.push_back(newBook);
    }

        void removeBook(const std::string& title) {
        auto it = std::find_if(books.begin(), books.end(), [title](const std::shared_ptr<Book>& book) {
            return book->getTitle() == title;
        });

        if (it != books.end()) {
            std::cout << "Removing Book: " << (*it)->getTitle() << std::endl;
            books.erase(it);
        } else {
            std::cout << "Book not found: " << title << std::endl;
        }
    }

    void displayBooks() {
        std::cout << "Library contains the following books:" << std::endl;
        for (const auto& book : books) {
            std::cout << book->getTitle() << " by " << book->getAuthor() << std::endl;
        }
    }

private:
    std::vector<std::shared_ptr<Book>> books;
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
