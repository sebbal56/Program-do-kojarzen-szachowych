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
	Player(std::string pauza, int code);
	Player() = default;
	int startingPosition;
	int getRating() const;
	std::string getSurname() const;
	std::string getName() const;
	const std::string playerInfo();
	std::string playerToFile();
	std::string playerToPairings();
	std::string playerToResults(int i);

	void addAsPlayedWith(int i, double result);

	static int nextStartingNumber; 
	double points;
	bool hasntPlayedWith(int i);
	std::vector<std::pair<int, double>> playersPlayedWith; //z kim ju¿ gra³ i jaki wynik 

	static bool comparePlayersByStarting(const Player& p1, const Player& p2);
	static void sortByStarting(std::vector<Player>& startingList);
	int matchDifferenceScore;
	void setBuch(std::vector<Player> listOfPlayers);
	double getBuch() const;

private:
	std::string surname;
	std::string name;
	std::string club;
	Date dateOfBirth;
	int rating;
	double buch;
};

