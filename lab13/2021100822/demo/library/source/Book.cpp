#include "Book.h"
#include <iostream>

Book::Book(const std::string& title, const std::string& author)
    : title(title), author(author) {}

Book::~Book() {
    std::cout << "Book '" << title << "' by " << author << " is being destroyed." << std::endl;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}