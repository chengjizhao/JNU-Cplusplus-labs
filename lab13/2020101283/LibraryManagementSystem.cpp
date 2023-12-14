#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Book {
public:
    Book(const std::string& title, const std::string& author) : title(title), author(author) {}

    void displayInfo() {
        std::cout << "Title: " << title << ", Author: " << author << std::endl;
    }

private:
    std::string title;
    std::string author;
};

class Library {
public:
    void addBook(const std::string& title, const std::string& author) {
        std::shared_ptr<Book> book = std::make_shared<Book>(title, author);
        books.push_back(book);
    }

    void removeBook(const std::string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if ((*it)->getTitle() == title) {
                books.erase(it);
                std::cout << "Book " << title << " is removed from the library." << std::endl;
                return;
            }
        }
        std::cout << "Book " << title << " is not found in the library." << std::endl;
    }

    void displayBooks() {
        std::cout << "Books in the library: " << std::endl;
        for (const auto& book : books) {
            book->displayInfo();
        }
    }

private:
    std::vector<std::shared_ptr<Book>> books;
};

int main() {
    Library library;

    library.addBook("The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.addBook("1984", "George Orwell");

    library.displayBooks();

    library.removeBook("To Kill a Mockingbird");

    library.displayBooks();

    return 0;
}  // 结束时，书籍对象将会被正确销毁
