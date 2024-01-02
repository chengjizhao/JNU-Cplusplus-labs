#include <iostream>
#include <memory>
#include <List>
#include <string>

class Book {
public:
    Book(const std::string& title, const std::string& author) : title(title), author(author) {
        std::cout<<"construct book: "<<title<<std::endl;
    }
    ~Book() {
        std::cout<<"destruct book: "<<title<<std::endl;
    }
    void displayInfo() {
        std::cout << "Title: " << title << ", Author: " << author << std::endl;
    }
    std::string getTitle() const {
        return title;
    }
private:
    std::string title;
    std::string author;
};

class Library {
public:
    ~Library() {
        std::cout<<"destruct Library: "<<std::endl;
    }
    // 添加书籍到图书馆
    void addBook(const std::string& title, const std::string& author) {
        std::shared_ptr<Book> newBook = std::make_shared<Book>(title, author);
        books.push_back(newBook);
        std::cout << "Book added to the library: " << title << std::endl;
    }

    // 从图书馆删除书籍
    void removeBook(const std::string& title) {
        std::list<std::shared_ptr<Book>>::iterator removeBook ;
        for (auto it = books.begin(); it != books.end(); it++) {
            if ( (*it) -> getTitle() == title )
            {
                removeBook = it;
                break;
            }
        }
        books.erase(removeBook);
    }

    // 显示图书馆中所有书籍
    void displayAllBooks() {
        std::cout << "Books in the library:" << std::endl;
        for (const auto& book : books) {
            book->displayInfo();
        }
    }

private:
    std::list<std::shared_ptr<Book>> books;
};

int main() {
    std::shared_ptr<Library>ptr_Library(new Library);

    // 向图书馆添加书籍
    ptr_Library->addBook("Book1", "Author1");
    ptr_Library->addBook("Book2", "Author2");
    ptr_Library->addBook("Book3", "Author3");

    // 显示图书馆中所有书籍
    ptr_Library->displayAllBooks();
    std::cout<<"------------remove book2----------------"<<std::endl;
    // 从图书馆删除书籍
    ptr_Library->removeBook("Book2");

    // 再次显示图书馆中所有书籍
    ptr_Library->displayAllBooks();

    // 对象在程序结束时由shared_ptr正确释放内存
    std::cout<<"------------程序结束，释放内存----------------"<<std::endl;
    return 0;
}
