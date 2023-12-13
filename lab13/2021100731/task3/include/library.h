#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/

class Book
{
public:
    Book(const char* name, const char* writer)
    {
        Book_Name = name;
        Writer = writer;
        cout << "A Book is Saved!" << endl;
    }
    ~Book()
    {
        cout << "A Book is Expired!" << endl;
    }

    const char* Book_Name;
    const char* Writer;
};

/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/

class Library
{
private:
    int BookNum = 0;
    vector<shared_ptr<Book>>Book_lib;
public:
    void Add_Book(const char* name, const char* writer);
    void Delete_Book(int num);
    void Delete_Book();
    void Show_Book();
};

#endif
