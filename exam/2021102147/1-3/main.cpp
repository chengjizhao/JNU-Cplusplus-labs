#include "Animal.h"


int main()
{
	Animal* ani[2];
	ani[0] = new Dog();
	ani[1] = new Cat();
	ani[0]->speak();
	ani[1]->speak();
}