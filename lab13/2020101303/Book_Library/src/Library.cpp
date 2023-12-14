#include "Library.h"
#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

string Book::get_Title() const
{
    return title;
}

string Book::get_Author() const
{
    return author;
}

void Library::add_Book(const string& title, const string& author)
{
    books.push_back(make_shared<Book>(title, author));
    cout << "Added: " << title << ", " << author << endl;
}

void Library::remove_Book(const string& title) 
{
    for (auto i = books.begin(); i != books.end(); i=i+1) 
    {
        if ((*i)->get_Title() == title) 
        {
            cout << "Removed book: " << title << endl;
            books.erase(i);
            return;
        }
    }
    cout << title << " not found! " << endl;
}

void Library::print_Books() const
{
    if (books.empty()) 
    {
        cout << "Library is empty." << endl;
    } 
    else
    {
        cout << "Library: " << endl;
        for (const auto& book : books)
        {
            cout << "-----" << book->get_Title() << " : " << book->get_Author() << endl;
        }
    }
}