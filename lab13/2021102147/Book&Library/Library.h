#pragma once

#include <string>
#include <memory>
#include <vector>


class Book
{
public:
	Book(const char* name, const char* author);
	~Book();
	const std::string& getAuthor()const;
	const std::string& getName()const;
	
private:
	std::string author, name;
};

class Library
{
public:
	void addBook(Book& b);
	void addBook(const char* name, const char* author);
	void removeBook(const char* name);
	void printAllBooks();
private:
	std::vector<std::shared_ptr<Book>>books;
};