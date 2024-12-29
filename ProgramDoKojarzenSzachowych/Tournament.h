#pragma once
#include <string>
#include "DateOfBirth.h"
#include "Player.h"
class Tournament
{
	std::string tournamentName;
	DateOfBirth tournamentDate; //trzeba zmienic nazwe klasy
	std::string tournamentArbiter;
	std::string tournamentPlace;
	std::string tournamentAbout;
	std::vector<Player> listOfPlayers;
};

