#pragma once
#include <string>
#include "Date.h"
#include "Player.h"
class Tournament
{
	std::string tournamentName;
	Date tournamentDate; //trzeba zmienic nazwe klasy
	std::string tournamentArbiter;
	std::string tournamentPlace;
	std::string tournamentAbout;
	std::vector<Player> listOfPlayers;
};

