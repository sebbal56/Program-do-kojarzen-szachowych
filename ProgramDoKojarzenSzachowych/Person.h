#pragma once
#include <iostream>
#include "DateOfBirth.h"

class Person
{
	std::string name;
	std::string surname;
	DateOfBirth dateOfBirth;

public:
	Person* next = nullptr;
	Person* previous = nullptr;
	void setPerson();
	void writePerson();
	int compare(const Person& pattern) const;
	Person() = default;
	Person(const Person& pattern);
	Person(std::string surname, std::string name, int d, int m, int y);
};

