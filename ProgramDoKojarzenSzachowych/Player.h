#pragma once
#include <string>
#include <vector>
#include <utility>
#include "Date.h"

// byæ mo¿e jakieœ dziedziczenie po person? idk jeszcze 


class Player
{
public:
	Player(std::string sn, std::string n, std::string club, Date bd, int rating);
	Player(std::string line);
	int startingPosition;
	int getRating();
	const std::string playerInfo();
	//friend std::ostream& operator<<(std::ostream& os, const Player& player);
	std::string playerToFile();

private:
	std::string surname;
	std::string name;
	std::string club;
	Date dateOfBirth;
	int rating;
	int points;
	std::vector<std::pair<int, int>> playersPlayedWith; //z kim ju¿ gra³ i jaki wynik 

};

