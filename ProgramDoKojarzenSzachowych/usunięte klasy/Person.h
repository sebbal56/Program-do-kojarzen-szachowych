#pragma once
#include <iostream>
#include "Date.h"

class Person
{
	std::string name;
	std::string surname;
	Date dateOfBirth;

public:
	Person* next = nullptr;
	Person* previous = nullptr;
	int compare(const Person& pattern) const;
	Person() = default;
	Person(const Person& pattern);
	std::string getSurname(); //tymczasowe do wywalenia?
	Person(std::string surname, std::string name, int d, int m, int y);
};

