#include "Library.h"

#include <iostream>

Book::Book(const char* name, const char* author)
{
	this->author = author;
	this->name = name;
}

Book::~Book()
{
	std::cout << name << " Destroyed\n";
}

const std::string& Book::getAuthor()const
{
	return author;
}

const std::string& Book::getName()const
{
	return name;
}

void Library::addBook(Book& b)
{
	auto sp = std::make_shared<Book>(b);
	books.push_back(sp);
}

void Library::addBook(const char* name, const char* author)
{
	auto sp = std::make_shared<Book>(name, author);
	books.push_back(sp);
}

void Library::removeBook(const char* name)
{
	for (auto it = books.begin(); it != books.end(); ++it)
	{
		if ((*it)->getName() == name)
		{
			books.erase(it);
			return;
		}
	}
}

void Library::printAllBooks()
{
	for (auto& i : books)
	{
		std::cout << "Name: " << i->getName() << " ";
		std::cout << "Author: " << i->getAuthor() << "\n";
	}
}
