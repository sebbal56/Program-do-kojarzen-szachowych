#pragma once
#include "Player.h"

class PairOfPlayers
{
	Player playerWhite;
	Player playerBlack;
	std::string gameResult;
public:
	std::string display();
	std::string displayResult();
	PairOfPlayers(Player p1, Player p2);
	PairOfPlayers(Player p1);
	void setResult(int result);
	int getWhitePlayer();
	int getBlackPlayer();
};

