#pragma once
#include <string>
#include "Date.h"
#include "Player.h"
#include <algorithm>

class Round;

class Tournament
{
	std::string tournamentName;
	Date tournamentDate; 
	std::string tournamentArbiter;
	std::string tournamentPlace;
	std::string tournamentAbout;
	

public:
	std::vector<Player> listOfPlayers;
	std::vector<Round> rounds;
	Tournament(std::string name, Date date, std::string place, std::string arbiter, std::string about);
	Tournament() = default;
	std::string getName();
	std::string getPlace();
	std::string getArbiter();
	std::string getAbout();
	Date getDate();
	void addPlayerToList(Player p);
	static bool comparePlayersByRating(const Player& p1, const Player& p2);
	static bool comparePlayersByPoints(const Player& p1, const Player& p2);
	static bool comparePlayersByStarting(const Player& p1, const Player& p2);
	void sortByRating(std::vector<Player>& startingList);
	void sortByPoints(std::vector<Player>& startingList);
	void sortByStarting(std::vector<Player>& startingList);

	bool firstColour = false;

	bool tournamentStarted = false; // zmienna maj¹ca za zadanie okrêliæ czy tueniej siê ju¿ zacz¹³ czy nie, Je¿eli siê zacz¹³, to nowododani zawodnicy 
	//nie powinni aktualizowaæ listy startowej, tylko wskakiwaæ na jej koniec


};

