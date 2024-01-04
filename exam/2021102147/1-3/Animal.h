#pragma once

class Animal
{
public:
	virtual void speak() = 0;
};

class Dog : public Animal
{
public:
	virtual void speak();
};

class Cat : public Animal
{
public:
	virtual void speak();
};