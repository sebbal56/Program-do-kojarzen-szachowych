#pragma once
#include "PairOfPlayers.h"
#include "Tournament.h"
#include <map>


class Round
{

public:
	Round();
	bool roundPaired;
	bool roundEnded;
	void firstRoundPairings(std::vector<Player> listOfPlayers, bool colour);
	void secoundRoundPairings(std::vector<Player> listOfPlayers, bool colour);
	void furtherRoundPairings(std::vector<Player> listOfPlayers, bool colour);
	std::vector<PairOfPlayers> pairings;
	std::vector<int> permutate(std::vector<int> startingPerm, std::vector<std::vector<int>> banned);

	struct Match
	{
		Player* a;
		Player* b;

		Match(Player* a, Player* b) :a(a), b(b) {}

		double ScoreDifference() const
		{
			return std::abs(a->points - b->points);
		}
		bool operator==(const Match& other) const
		{
			return (a == other.a && b == other.b) || (a == other.b && b == other.a);
		}
	};

};

