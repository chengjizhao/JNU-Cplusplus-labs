#include <iostream>

#include "Library.h"

int main()
{
	Library lib;
	lib.addBook("Ero manga sensei", "Fushimi Tsukasa");
	lib.addBook("Wan shui qian shan zou bian", "Sanmao");
	lib.addBook("Das Kapital", "Karl Marx");

	lib.printAllBooks();

	lib.removeBook("Das Kapital");
	lib.printAllBooks();
}