#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class classBook
{
public:
	classBook(const string& title, const string& author) : title(title), author(author)
	{
		cout << "The book \"" << title << "\" by " << author << " has been created." << endl;
	}
	~classBook()
	{
		cout << "The book \"" << title << "\" by " << author << " has been removed." << endl;
	}

	string getTitle() const
	{
		return title;
	}
	string getAuthor() const
	{
		return author;
	}
private:
	string title;
	string author;
};

class classLibrary
{
public:
	void creatBook(const shared_ptr<classBook>& book)
	{
		Books.push_back(book);
	}
	void deleteBook(const string& title)
	{
		for (auto i = Books.begin(); i != Books.end(); i++)
		{
			if ((*i)->getTitle() == title)
			{
				Books.erase(i);
				cout << title << "has been deleted" << endl;
				break;
			}
		}
	}
	void displayBook()
	{
		cout << "there are ";
		for (auto i = Books.begin(); i != Books.end(); i++)
		{
			cout << "\"" << (*i)->getTitle() << "\" by " << (*i)->getAuthor();
			if (i != (Books.end()-1))
			{
				cout << ", ";
			}
			else
			{
				cout << " in the library" << endl;
			}
		}
	}
private:
	vector<shared_ptr<classBook>> Books;
};

int main()
{
	classLibrary myLibrary;
	myLibrary.creatBook(make_shared<classBook>("book1", "author1"));
	myLibrary.creatBook(make_shared<classBook>("book2", "author2"));
	myLibrary.creatBook(make_shared<classBook>("book3", "author3"));
	myLibrary.displayBook();
	myLibrary.deleteBook("book2");
	myLibrary.displayBook();
	return 0;
}