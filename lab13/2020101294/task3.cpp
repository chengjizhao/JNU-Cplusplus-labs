#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

class Book {
public:
    Book(const std::string& title, const std::string& author)
        : title(title), author(author) {}

    void displayInfo() const {
        std::cout << "书名：" << title << "，作者：" << author << std::endl;
    }

    const std::string& getTitle() const {
        return title;
    }

private:
    std::string title;
    std::string author;
};

class Library {
public:
    void addBook(const std::string& title, const std::string& author) {
        books.push_back(std::make_shared<Book>(title, author));
        std::cout << "成功添加书籍：" << title << std::endl;
    }

    void removeBook(const std::string& title) {
        auto it = std::remove_if(books.begin(), books.end(),
                                 [&title](const std::shared_ptr<Book>& book) {
                                     return book->getTitle() == title;
                                 });

        if (it != books.end()) {
            books.erase(it, books.end());
            std::cout << "成功删除书籍：" << title << std::endl;
        } else {
            std::cout << "未找到要删除的书籍：" << title << std::endl;
        }
    }

    void displayBooks() const {
        std::cout << "图书馆中的书籍：" << std::endl;
        for (const auto& book : books) {
            book->displayInfo();
        }
    }

private:
    std::vector<std::shared_ptr<Book>> books;
};

int main() {
    Library library;

    int choice;

    do {
        std::cout << "\n图书馆管理系统\n";
        std::cout << "1. 添加书籍\n";
        std::cout << "2. 删除书籍\n";
        std::cout << "3. 显示所有书籍\n";
        std::cout << "0. 退出\n";
        std::cout << "请输入您的选择: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string title, author;
                std::cout << "请输入书名: ";
                std::cin >> title;
                std::cout << "请输入作者: ";
                std::cin >> author;
                library.addBook(title, author);
                break;
            }
            case 2: {
                std::string title;
                std::cout << "请输入要删除的书名: ";
                std::cin >> title;
                library.removeBook(title);
                break;
            }
            case 3:
                library.displayBooks();
                break;
            case 0:
                std::cout << "程序退出\n";
                break;
            default:
                std::cout << "无效的选择，请重新输入\n";
        }

    } while (choice != 0);

    return 0;
}