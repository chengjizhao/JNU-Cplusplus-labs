#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Book
{
    public:
        Book(const string& title, const string& author) : title(title), author(author) {}

        string getTitle() const
        {
            return title;
        }

    private:
        string title;
        string author;
};

class Library
{
    public:
        void addBook(shared_ptr<Book> book)
        {
            books.push_back(book);
        }

        void removeBook(const string& title)
        {
            for (auto it = books.begin(); it != books.end(); ++it)
            {
                if ((*it)->getTitle() == title)
                {
                    books.erase(it);
                    break;
                }
            }
        }

        void displayBooks() const
        {
            cout << "Library contains the following books:" << endl;
            for (const auto& book : books)
            {
                cout << "- " << book->getTitle() << endl;
            }
        }

    private:
        vector<std::shared_ptr<Book>> books;
};

int main() {
    // 创建图书馆对象
    Library library;

    // 添加书籍到图书馆
    shared_ptr<Book> book1 = make_shared<Book>("Book1", "Author1");
    shared_ptr<Book> book2 = make_shared<Book>("Book2", "Author2");
    shared_ptr<Book> book3 = make_shared<Book>("Book3", "Author3");

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    // 显示图书馆中的所有书籍
    library.displayBooks();

    // 从图书馆中删除一本书籍
    library.removeBook("Book2");

    // 再次显示图书馆中的所有书籍
    library.displayBooks();

    return 0;
}
