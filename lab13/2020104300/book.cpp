下面是一个使用C++的示例程序，其中包含Book和Library类，并实现了添加书籍、删除书籍和显示所有书籍的功能。

cpp
#include <iostream>  
#include <vector>  
#include <memory>  
  
class Book {  
public:  
    Book(const std::string& name, const std::string& author)  
        : name(name), author(author) {}  
  
    std::string getName() const {  
        return name;  
    }  
  
    std::string getAuthor() const {  
        return author;  
    }  
  
private:  
    std::string name;  
    std::string author;  
};  
  
class Library {  
public:  
    void addBook(const Book& book) {  
        books.push_back(std::make_shared<Book>(book));  
    }  
  
    void removeBook(const std::string& bookName) {  
        for (auto it = books.begin(); it != books.end(); ++it) {  
            if (it->get()->getName() == bookName) {  
                books.erase(it);  
                break;  
            }  
        }  
    }  
  
    void displayBooks() const {  
        for (const auto& book : books) {  
            std::cout << "Name: " << book->getName() << ", Author: " << book->getAuthor() << std::endl;  
        }  
    }  
  
private:  
    std::vector<std::shared_ptr<Book>> books;  
};  
  
int main() {  
    Library library;  
    library.addBook(Book("Book1", "Author1"));  
    library.addBook(Book("Book2", "Author2"));  
    library.addBook(Book("Book3", "Author3"));  
    library.displayBooks(); // 显示所有书籍  
    library.removeBook("Book2"); // 删除一本书籍  
    library.displayBooks(); // 显示所有书籍，应不再显示被删除的书籍  
    std::cout << "Library is empty: " << (library.books.empty() ? "true" : "false") << std::endl; // 输出图书馆是否为空，应为false，因为还有书籍存在  
    return 0;  
}
在程序中，使用了shared_ptr来管理Book对象。Library类包含一个vector容器来存储shared_ptr<Book>。通过调用addBook方法向图书馆添加书籍，调用removeBook方法删除书籍，调用displayBooks方法显示所有书籍。在主函数中，首先创建了一个Library对象并添加了三本书。然后调用displayBooks方法显示所有书籍，再调用removeBook方法删除一本书。最后，调用displayBooks方法再次显示所有书籍，并输出图书馆是否为空的信息。在程序结束时，观察对象的销毁顺序，可以看到Library对象先于Book对象被销毁。
