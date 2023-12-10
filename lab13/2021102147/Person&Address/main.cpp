
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <fstream>
#include "Person.h"

inline void print_info(Person& p)
{
	std::cout << "Name:" << p.getName() << std::endl;
	std::cout << "Age:" << p.getAge() << std::endl;
	std::cout << "Address:";
	p.printAddr();
	std::cout << std::endl;
}

int main()
{
	std::vector <std::shared_ptr<Person>>persons_ptr;

	Address addr1("Pokfulam, Hong Kong"), addr2("San Jose, United States");

	std::ifstream fin("info.txt");
	std::string name;
	int age;
	std::shared_ptr<Person> tmp;

	// The first family (three people)
	for (int i = 0; i < 3; ++i)
	{
		fin >> name >> age;
		// shared指针一旦被释放，对应的弱指针就会expire
		// 因此要事先进行保存
		tmp = std::make_shared<Person>(*(new Person(name, age, addr1)));
		persons_ptr.push_back(tmp);
		addr1.addPerson(tmp);
	}

	// The second family (two people)
	for (int i = 0; i < 2; ++i)
	{
		fin >> name >> age;
		tmp = std::make_shared<Person>(*(new Person(name, age, addr2)));
		persons_ptr.push_back(tmp);
		addr2.addPerson(tmp);
	}


	std::cout << "### The first family ###" << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		print_info(*(persons_ptr[i].get()));
	}

	std::cout << "### The second family ###" << std::endl;
	for (int i = 3; i < 5; ++i)
	{
		print_info(*(persons_ptr[i].get()));
	}

	std::cout << "Who lives in the first address?" << std::endl;
	const auto& v = addr1.getPersons();
	for (auto i : v)
	{
		std::cout << i.lock()->getName() << std::endl;
	}

	std::cout << "Who lives in the second address?" << std::endl;
	const auto& v2 = addr2.getPersons();
	for (auto i : v2)
	{
		if (!i.expired())
			std::cout << i.lock()->getName() << std::endl;
	}

	return 0;
}