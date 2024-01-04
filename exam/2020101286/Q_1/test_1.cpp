#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;

public:
    Book(const std::string &title, const std::string &author) : title(title), author(author) {}

    void display() {
        std::cout << "书名: " << title << "\n作者: " << author << std::endl;
    }
};

int main() {
    Book *book = new Book("C++ Primer", "Stanley B. Lippman");

    book->display();

    delete book;

    return 0;
}