#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Book
{
public:
    Book(const std::string &title, const std::string &author)
        : title(title), author(author) {}

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }

private:
    std::string title;
    std::string author;
};

class Library
{
public:
    void addBook(const std::shared_ptr<Book> &book)
    {
        books.push_back(book);
    }

    void removeBook(const std::shared_ptr<Book> &book)
    {
        for (auto it = books.begin(); it != books.end(); ++it)
        {
            if (*it == book)
            {
                books.erase(it);
                break;
            }
        }
    }

    void displayBooks() const
    {
        for (const auto &book : books)
        {
            std::cout << "Title: " << book->getTitle() << ", Author: " << book->getAuthor() << std::endl;
        }
    }

private:
    std::vector<std::shared_ptr<Book>> books;
};

int main()
{
    Library library;
    std::shared_ptr<Book> book1 = std::make_shared<Book>("Harry Potter and the Sorcerer's Stone", "J.K. Rowling");
    std::shared_ptr<Book> book2 = std::make_shared<Book>("To Kill a Mockingbird", "Harper Lee");
    library.addBook(book1);
    library.addBook(book2);
    library.displayBooks();    // 显示所有书籍
    library.removeBook(book1); // 删除书籍
    library.displayBooks();    // 再次显示所有书籍，以验证书籍已被删除
    return 0;
}