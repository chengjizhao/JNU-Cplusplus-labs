#include <iostream>
#include <vector>
#include <memory>

using namespace std;
class Book {
public:
    Book(const string& title, const string& author)
        : title(title), author(author) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

private:
    string title;
    string author;
};

class Library {
public:
    void addBook(const string& title, const string& author) {
        shared_ptr<Book> book = make_shared<Book>(title, author);
        books.push_back(book);
    }

    void removeBook(const string& title, const string& author) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            shared_ptr<Book> book = *it;
            if (book->getTitle() == title && book->getAuthor() == author) {
                books.erase(it);
                break;
            }
        }
    }

    void displayBooks() const {
        cout << "Library books:" << endl;
        for (const auto& book : books) {
            cout << book->getTitle() << " by " << book->getAuthor() << endl;
        }
    }

private:
    vector<shared_ptr<Book>> books;
};

int main() {
    Library library;

    // 添加书籍
    library.addBook("Book 1", "Author 1");
    library.addBook("Book 2", "Author 2");
    library.addBook("Book 3", "Author 3");

    // 显示所有书籍
    library.displayBooks();

    // 删除书籍
    library.removeBook("Book 2", "Author 2");

    // 显示剩余的书籍
    library.displayBooks();

    // 在程序结束时输出相关信息，观察对象的销毁顺序

    return 0;
}