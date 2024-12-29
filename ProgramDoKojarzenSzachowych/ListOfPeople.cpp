#include "ListOfPeople.h"

void ListOfPeople::addPerson(const Person& p)
{
	Person* p2 = new Person(p);
	if (head == nullptr) {
		head = p2;
		//m_nLiczbaPracownikow = 1;
		return;
	}

	int a = head->compare(p);
	if (a == 0) return;
	Person* x = head;
	if (a < 0) {
		while (x->next != nullptr && a < 0) {
			a = x->next->compare(p);
			if (a == 0) return;
			if (a > 0) break;
			x = x->next;
		}
		p2->next = x->next;
		x->next = p2;
		p2->previous = x;
		if (p2->next != nullptr) p2->next->previous = p2;
	}
	else {
		p2->next = x;
		x->previous = p2;
		p2->previous = nullptr;
		head = p2;
	}
	//m_nLiczbaPracownikow++;
}

void ListOfPeople::writeAllPeople() const
{
	Person* x = head;
	while (x != nullptr) {
		x->writePerson();
		x = x->next;
	}
}

std::string ListOfPeople::getSurnameOfHead() {
	return head->getSurname();
}

ListOfPeople::ListOfPeople() : head(nullptr){

}