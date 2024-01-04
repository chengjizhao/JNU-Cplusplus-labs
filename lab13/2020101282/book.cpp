#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Book {
public:
    Book(const std::string& title, const std::string& author) : title(title), author(author) {}

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
        auto it = std::find_if(books.begin(), books.end(),
                               [title](const std::shared_ptr<Book>& book) {
                                   return book->getTitle() == title;
                               });

        if (it != books.end()) {
            books.erase(it);
            std::cout << "Book removed from the library: " << title << std::endl;
        } else {
            std::cout << "Book not found in the library: " << title << std::endl;
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
    Library library;

    // 添加书籍
    library.addBook("The Catcher in the Rye", "J.D. Salinger");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.addBook("1984", "George Orwell");

    // 显示所有书籍
    library.displayBooks();

    // 删除一本书籍
    library.removeBook("To Kill a Mockingbird");

    // 显示更新后的书籍
    library.displayBooks();

    // 在程序结束时，观察对象的销毁顺序

    return 0;
}
