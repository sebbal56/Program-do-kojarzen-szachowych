#pragma once
#include <string>
#include "Date.h"
#include "Player.h"
class Tournament
{
	std::string tournamentName;
	Date tournamentDate; 
	std::string tournamentArbiter;
	std::string tournamentPlace;
	std::string tournamentAbout;
	std::vector<Player> listOfPlayers;
public:
	Tournament(std::string name, Date date, std::string place, std::string arbiter, std::string about);
	Tournament() = default;
	std::string getName();
	std::string getPlace();
	std::string getArbiter();
	std::string getAbout();
	Date getDate();
	void addPlayerToList(Player p);
};

