#pragma once
#include "PairOfPlayers.h"


class Round
{
	std::vector<PairOfPlayers> pairings;
public:
	Round();
	bool roundPaired;
	bool roundEnded;
};

