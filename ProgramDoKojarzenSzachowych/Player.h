#pragma once
#include <string>
#include <vector>
#include <utility>
#include "Date.h"

// byæ mo¿e jakieœ dziedziczenie po person? idk jeszcze 


class Player
{
	std::string surname;
	std::string name;
	Date dateOfBirth;
	int startingPosition;
	int rating;
	int points;
	std::vector<std::pair<int, int>> playersPlayedWith; //z kim ju¿ gra³ i jaki wynik 

};

