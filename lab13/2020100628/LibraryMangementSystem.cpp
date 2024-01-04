#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Book {
public:
    Book(const std::string& title, const std::string& author) : title(title), author(author) {
        std::cout << "Book: " << title << " by " << author << " constructed." << std::endl;
    }

    ~Book() {
        std::cout << "Book: " << title << " by " << author << " destructed." << std::endl;
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
    void addBook(const std::shared_ptr<Book>& book) {
        books.push_back(book);
    }

    void removeBook(const std::string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if ((*it)->getTitle() == title) {
                std::cout << "Removing book: " << (*it)->getTitle() << " by " << (*it)->getAuthor() << std::endl;
                books.erase(it);
                break;
            }
        }
    }

    void displayBooks() const {
        std::cout << "Books in the library:" << std::endl;
        for (const auto& book : books) {
            std::cout << book->getTitle() << " by " << book->getAuthor() << std::endl;
        }
    }

private:
    std::vector<std::shared_ptr<Book>> books;
};

int main() {
    // 创建图书馆对象
    Library library;

    // 添加书籍
    library.addBook(std::make_shared<Book>("Book 1", "Author 1"));
    library.addBook(std::make_shared<Book>("Book 2", "Author 2"));
    library.addBook(std::make_shared<Book>("Book 3", "Author 3"));

    // 显示所有书籍
    library.displayBooks();

    // 删除书籍
    library.removeBook("Book 2");

    // 显示更新后的书籍列表
    library.displayBooks();

    return 0;
}
