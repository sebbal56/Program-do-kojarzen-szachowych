#pragma once
#include "PairOfPlayers.h"
#include "Tournament.h"


class Round
{

public:
	Round();
	bool roundPaired;
	bool roundEnded;
	void firstRoundPairings(std::vector<Player> listOfPlayers, bool colour);
	void secoundRoundPairings(std::vector<Player> listOfPlayers, bool colour);
	std::vector<PairOfPlayers> pairings;
};

