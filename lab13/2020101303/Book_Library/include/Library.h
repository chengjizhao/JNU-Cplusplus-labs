#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class Book 
{
    public:
       Book(const string& title_, const string& author_) : title(title_), author(author_) {}
       string get_Title() const;
       string get_Author() const;
       ~Book() {cout << "Destroy -- Book: " << title << ", " << author << endl;}
    private:
       string title;
       string author;
};

class Library 
{
    public:
       void add_Book(const string& title, const string& author);
       void remove_Book(const string& title);
       void print_Books() const;
       ~Library() {cout << "Destroy -- Library" << endl;}
    private:
       vector<shared_ptr<Book>> books;
};

#endif