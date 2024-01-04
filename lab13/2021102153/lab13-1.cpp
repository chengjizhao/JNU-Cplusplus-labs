#include <string>
#include <memory>
#include <vector>
#include <iostream>
using namespace std;
class Book
{
private:
	std::string author, name;
public:
	Book(const char* name1, const char* author1)
    {
    this->author = author1;
	this->name = name1;
    };
	~Book()
    {
        std::cout << name << " Destroyed" <<endl;
    };
	const std::string& getAuthor()const
    {
        return author;
    };
	const std::string& getName()const
    {
        return name;
    };
	

};

class Library
{
public:
	void addBook(Book& b)
    {
    auto sp = std::make_shared<Book>(b);
	books.push_back(sp);
    };
	void addBook(const char* name, const char* author)
    {
    auto sp = std::make_shared<Book>(name, author);
	books.push_back(sp);
    };
	void removeBook(const char* name)
    {
        for (auto it = books.begin(); it != books.end(); ++it)
	{
		if ((*it)->getName() == name)
		{
			books.erase(it);
			return;
		}
	}
    };
	void printAllBooks()
    {
    for (auto& i : books)
	{
		std::cout << "名称: " << i->getName() << " ";
		std::cout << "作者: " << i->getAuthor() << "\n";
	}
    };
private:
	std::vector<std::shared_ptr<Book>>books;
};
int main()
{
	Library lib;
	lib.addBook("E", "F");
	lib.addBook("W", "S");
	lib.addBook("D K", "K M");
	lib.printAllBooks();
	lib.removeBook("D K");
	lib.printAllBooks();
}