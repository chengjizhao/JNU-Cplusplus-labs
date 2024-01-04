#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

class Book {
public:
    std::string title;
    std::string author;

    Book(const std::string& title, const std::string& author) : title(title), author(author) {
        std::cout << "Creating book: " << title << " by " << author << std::endl;
    }

    ~Book() {
        std::cout << "Destroying book: " << title << " by " << author << std::endl;
    }
};

class Library {
public:
    std::vector<std::shared_ptr<Book>> books;

    void addBook(const std::shared_ptr<Book>& book) {
        books.push_back(book);
        std::cout << "Book added to library: " << book->title << std::endl;
    }

    void removeBook(const std::shared_ptr<Book>& book) {
        auto it = std::find_if(books.begin(), books.end(), [&](const std::shared_ptr<Book>& b) { return b == book; });
        if (it != books.end()) {
            books.erase(it);
            std::cout << "Book removed from library: " << book->title << std::endl;
        }
    }

    void displayBooks() {
        std::cout << "Books in the library:\n";
        for (const auto& book : books) {
            std::cout << book->title << " by " << book->author << std::endl;
        }
    }
};

int main() {
    Library library;

    std::shared_ptr<Book> book1 = std::make_shared<Book>("The Dream of Red Mansion", "Cao Xueqin");
    std::shared_ptr<Book> book2 = std::make_shared<Book>("Journey to the West", "Wu Cheng'en");

    library.addBook(book1);
    library.addBook(book2);

    library.displayBooks();

    library.removeBook(book1);

    return 0;
}