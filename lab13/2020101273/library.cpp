#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Book {
public:
    Book(const string& name, const string& author) : name_(name), author_(author) {}
    const string& getName() const {
        return name_;
    }
    const string& getAuthor() const {
        return author_;
    }
private:
    string name_;
    string author_;
};
class Library {
public:
    Library() : books_() {}
    void addBook(const string& name,const string& author) {
        shared_ptr<Book> book = make_shared<Book>(name, author);
        books_.push_back(book);
    }
    void removeBook(const string& name) {
	    for (auto it = books_.begin(); it != books_.end(); ++it)
	    {
		    if ((*it)->getName() == name)
		    {
			    books_.erase(it);
			    return;
		    }
	    }   
    }
    void displayBooks() const {
        cout << "All books:" << endl;
        for (const auto& book : books_) {
            cout << book->getName() << " by " << book->getAuthor() << endl;
        }
    }
    ~Library() {
        for (const auto& book : books_) {
            cout << "Destroy: " << book->getName() << endl;
        }
}

//private:
    vector<shared_ptr<Book>> books_;
};

int main() {
    Library library;

    library.addBook("Book1", "Author1");
    library.addBook("Book2", "Author2");
    library.addBook("Book3", "Author3");
    library.displayBooks();

    library.removeBook("Book1");
    library.displayBooks();

    library.removeBook("Book2");
    library.addBook("Book4", "Author4");
    library.displayBooks();

    return 0;
}