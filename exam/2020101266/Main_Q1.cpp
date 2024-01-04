#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;

public:
    Book(const std::string& title, const std::string& author) : title(title), author(author) {}

    void display() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
    }
};

int main() {
    // Dynamically create a Book object
    Book* myBook = new Book("The Great Gatsby", "F. Scott Fitzgerald");

    // Call display function to show book information
    myBook->display();

    // Delete the dynamically allocated object to free memory
    delete myBook;

    return 0;
}
