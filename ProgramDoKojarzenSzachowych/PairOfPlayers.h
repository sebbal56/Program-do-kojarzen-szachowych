#pragma once
#include "Player.h"

class PairOfPlayers
{
	Player playerWhite;
	Player playerBlack;
public:
	std::string display();
	PairOfPlayers(Player& p1, Player& p2);
};

