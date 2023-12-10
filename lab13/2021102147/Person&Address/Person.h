#pragma once

#include <string>
#include <memory>
#include <vector>


class Address;

class Person
{
public:
	Person(const std::string& name, int age, Address& addr);
	std::string getName()const;
	int getAge()const;
	void printAddr()const;


private:
	std::string name;
	int age;
	std::shared_ptr<Address> addr;
};

class Address
{
public:
	Address(const char* addr);
	void printAddr()const;
	void setAddr(const char* addr);
	void addPerson(std::shared_ptr<Person> sp);
	const std::vector<std::weak_ptr<Person>>& getPersons()const;
private:
	std::string addr;
	std::vector<std::weak_ptr<Person>> persons;
};