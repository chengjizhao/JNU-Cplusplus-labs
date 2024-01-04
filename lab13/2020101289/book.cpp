#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Book {
public:
    Book(string name, string author) : name_(name), author_(author) {}
    string getName() const { return name_; }
    string getAuthor() const { return author_; }
private:
    string name_;
    string author_;
};

class Library {
public:
    void addBook(shared_ptr<Book> book) { books_.push_back(book); }
    void removeBook(shared_ptr<Book> book) { books_.erase(find(books_.begin(), books_.end(), book)); }
    void showBooks() const {
        for (const auto& book : books_) {
            cout << "Book name: " << book->getName() << ", author: " << book->getAuthor() << endl;
        }
    }
private:
    vector<shared_ptr<Book>> books_;
};

int main() {
    Library library;
    shared_ptr<Book> book1 = make_shared<Book>("BOOK111", "ZUOZHE1");
    shared_ptr<Book> book2 = make_shared<Book>("BOOK222", "ZUOZHE2");
    shared_ptr<Book> book3 = make_shared<Book>("BOOK333", "ZUOZHE3");
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.showBooks();
    library.removeBook(book2);
    library.showBooks();
    return 0;
}