#include "library.h"

void Library::Add_Book(const char* name, const char* writer)
{
    shared_ptr<Book> book(new Book(name, writer));
    Book_lib.push_back(book);
    BookNum++;
}

void Library::Delete_Book(int num)
{
    auto lib_Ptr = Book_lib.begin();
    Book_lib.erase(lib_Ptr + num - 1);
    BookNum--;
}

void Library::Delete_Book()
{
    Book_lib.pop_back();
    BookNum--;
}

void Library::Show_Book()
{
    for(int i=1; i<=BookNum; i++)
    {
        cout << "Book " << i << ": " << endl;
        cout << "Name: " << Book_lib[i-1]->Book_Name << "   "
             << "Writer: " << Book_lib[i-1]->Writer << endl;
    }
}
