#include "Round.h"

Round::Round(){
	roundPaired = false; //tymczasowo
	roundEnded = false;
	pairings = {};
}

void Round::firstRoundPairings(std::vector<Player> listOfPlayers, std::string colour){
	bool currColour = colour == "Bia�y"; //zmienna odpowiadaj�ca kto b�dzie bi�y a kto czarny
	int n = listOfPlayers.size() / 2;
	for (int i = 0; i < n; i++) {
		if (currColour) pairings.push_back(PairOfPlayers(listOfPlayers[i], listOfPlayers[i + n]));
		else pairings.push_back(PairOfPlayers(listOfPlayers[i + n], listOfPlayers[i]));
		currColour = !currColour;
	}

}
