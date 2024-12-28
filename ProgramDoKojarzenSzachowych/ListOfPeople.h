#pragma once
#include "Person.h"
class ListOfPeople
{
	Person* head;
	//int m_nLiczbaPracownikow;


public:
	void addPerson(const Person& person);
	void writeAllPeople() const;
	ListOfPeople();

};

