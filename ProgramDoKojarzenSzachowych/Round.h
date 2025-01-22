#pragma once
#include "PairOfPlayers.h"
#include "Tournament.h"


class Round
{

public:
	Round();
	bool roundPaired;
	bool roundEnded;
	void firstRoundPairings(std::vector<Player> listOfPlayers, std::string colour);
	void secoundRoundPairings(std::vector<Player> listOfPlayers);
	std::vector<PairOfPlayers> pairings;
};

