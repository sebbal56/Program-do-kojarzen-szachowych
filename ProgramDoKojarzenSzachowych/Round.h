#pragma once
#include "PairOfPlayers.h"


class Round
{
	std::vector<PairOfPlayers> pairings;
	bool roundEnded;
public:
	Round();
};

