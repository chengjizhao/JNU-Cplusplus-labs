#include "Library.h"

int main() {
    Library library;

    library.addBook("123", "123");
    library.displayBooks();

    library.removeBook("removed");
    library.displayBooks();

    return 0;
}