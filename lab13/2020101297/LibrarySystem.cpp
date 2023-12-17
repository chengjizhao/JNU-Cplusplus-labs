#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Book {
public:
    Book(const std::string& title, const std::string& author)
    {
        m_title = title ; 
        m_author = author;
        std::cout << "Creating Book: " << title << " by " << author << std::endl;
    }
    ~Book() {
        std::cout << "Destroying Book: " << m_title << " by " << m_author << std::endl;
    }

    std::string getTitle() const {
        return m_title;
    }

    std::string getAuthor() const {
        return m_author;
    }

private:
    std::string m_title;
    std::string m_author;
};

class Library {
public:
    void addBook(const std::shared_ptr<Book>& book) {
        books.push_back(book);
    }

    void removeBook(const std::string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if ((*it)->getTitle() == title) {
                books.erase(it);
                break;
            }
        }
    }

    void displayBooks() const {
        std::cout << "Library contains the following books:" << std::endl;
        for (const auto& book : books) {
            std::cout << "- " << book->getTitle() << " by " << book->getAuthor() << std::endl;
        }
    }

private:
    std::vector<std::shared_ptr<Book>> books;
};

int main() {
    Library library;

    // 添加书籍
    std::shared_ptr<Book> book1(new Book("Book 1", "Author 1"));
    std::shared_ptr<Book> book2(new Book("Book 2", "Author 2"));
    std::shared_ptr<Book> book3(new Book("Book 3", "Author 3"));

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    // 显示图书馆中的书籍
    library.displayBooks();

    // 删除一本书
    library.removeBook("Book 2");

    // 再次显示图书馆中的书籍
    library.displayBooks();

    // 输出相关信息
    std::cout << "Program finished!" << std::endl;

    return 0;
}
