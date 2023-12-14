#include "Library.h"
#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

int main() 
{
    Library library;

    library.remove_Book("Book1");
    library.add_Book("Book1", "Author1");
    library.add_Book("Book2", "Author2");
    library.add_Book("Book3", "Author3");
    library.print_Books();
    library.remove_Book("Book2");
    library.print_Books();
}