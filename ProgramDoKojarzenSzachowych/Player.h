#pragma once
#include <string>
#include <vector>
#include <utility>
#include "Date.h"
#include <iomanip> // std::setw, std::setfill
#include <sstream> // std::ostringstream



class Player
{
public:
	Player(std::string sn, std::string n, std::string club, Date bd, int rating);
	Player(std::string line);
	Player() = default;
	int startingPosition;
	int getRating() const;
	std::string getSurname() const;
	std::string getName() const;
	const std::string playerInfo();
	//friend std::ostream& operator<<(std::ostream& os, const Player& player);
	std::string playerToFile();
	std::string playerToPairings();
	std::string playerToResults(int i);

	static int nextStartingNumber; 
	double points;

private:
	std::string surname;
	std::string name;
	std::string club;
	Date dateOfBirth;
	int rating;

	std::vector<std::pair<int, int>> playersPlayedWith; //z kim ju¿ gra³ i jaki wynik 

};

