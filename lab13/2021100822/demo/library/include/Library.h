#ifndef LIBRARY_H
#define LIBRARY_H

#include <memory>
#include <vector>
#include "Book.h"

class Book;

class Library {
public:
    Library();
    void addBook(const std::string& title, const std::string& author);
    void removeBook(const std::string& title);
    void displayBooks() const;

private:
    std::vector<std::shared_ptr<Book>> books;
};

#endif // LIBRARY_H