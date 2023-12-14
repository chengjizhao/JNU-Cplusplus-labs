#include "Library.h"
#include <iostream>

Library::Library() {}

void Library::addBook(const std::string& title, const std::string& author) {
    std::shared_ptr<Book> newBook = std::make_shared<Book>(title, author);
    books.push_back(newBook);
    std::cout << "Added book: " << title << " by " << author << std::endl;
}

void Library::removeBook(const std::string& title) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if ((*it)->getTitle() == title) {
            books.erase(it);
            std::cout << "Removed book: " << title << std::endl;
            return;
        }
    }
    std::cout << "Book not found: " << title << std::endl;
}

void Library::displayBooks() const {
    std::cout << "Books in the library:" << std::endl;
    for (const auto& book : books) {
        std::cout << book->getTitle() << " by " << book->getAuthor() << std::endl;
    }
}