#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    Book(const std::string& title, const std::string& author);
    ~Book();

    std::string getTitle() const;
    std::string getAuthor() const;

private:
    std::string title;
    std::string author;
};

#endif // BOOK_H