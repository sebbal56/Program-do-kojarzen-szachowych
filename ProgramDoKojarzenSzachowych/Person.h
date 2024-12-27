#pragma once
#include <iostream>
#include "DateOfBith.h"

class Person
{
	std::string name;
	std::string surname;
	DateOfBirth dateOfBirth;

public:
	void setPerson();
	void writePerson();
};

