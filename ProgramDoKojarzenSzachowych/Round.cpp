#include "Round.h"

Round::Round(){
	roundPaired = false; //tymczasowo
	roundEnded = false;
	pairings = {};
}

void Round::firstRoundPairings(std::vector<Player> listOfPlayers, bool colour){
	int n = listOfPlayers.size() / 2;
	for (int i = 0; i < n; i++) {
		if (colour) pairings.push_back(PairOfPlayers(listOfPlayers[i], listOfPlayers[i + n]));
		else pairings.push_back(PairOfPlayers(listOfPlayers[i + n], listOfPlayers[i]));
		colour = !colour;
	}
	if(listOfPlayers.size() % 2 == 1) pairings.push_back(PairOfPlayers(listOfPlayers[listOfPlayers.size() - 1]));

}

void Round::secoundRoundPairings(std::vector<Player> listOfPlayers, bool colour){
	int i = 0;
	std::vector<Player> temp = {};
	while(listOfPlayers[i].points == 1){
		temp.push_back(listOfPlayers[i]);
		i++;
	}
	int n = temp.size() / 2;
	for(int j = 0; j < n; j++){
		if(colour)
			pairings.push_back(PairOfPlayers(temp[j], temp[j + n]));
		else
			pairings.push_back(PairOfPlayers(temp[j + n], temp[j]));
		colour = !colour;
	}
	if (temp.size() % 2 == 1) {
		temp.clear();
		temp.push_back(listOfPlayers[n*2]);
	}
	else {
		temp.clear();
	}
	while(i < listOfPlayers.size() && listOfPlayers[i].points == 0.5) {
		temp.push_back(listOfPlayers[i]);
		i++;
	}

	while(temp.size() > 1){
		bool paired = false;
		for (int j = 0; j < temp.size(); j++) {
			for (int z = j + 1; z < temp.size(); z++) {
				if (temp[j].hasntPlayedWith(listOfPlayers[z].startingPosition)) {
					paired = true;
					if(colour)
						pairings.push_back(PairOfPlayers(temp[j], temp[z]));
					else
						pairings.push_back(PairOfPlayers(temp[z], temp[j]));
					colour = !colour;
					temp.erase(temp.begin() + z);
					temp.erase(temp.begin() + j);
					break;
				}
			}
			if(paired) break;
		}
		if (!paired) break;
	}
	for(i; i < listOfPlayers.size(); i++){
		temp.push_back(listOfPlayers[i]);
	}

	n = temp.size() / 2;
	for(int i = 0; i < n; i++){
		if(colour)
			pairings.push_back(PairOfPlayers(temp[i], temp[i + n]));
		else
			pairings.push_back(PairOfPlayers(temp[i + n], temp[i]));
	}
	if(temp.size() % 2 == 1) pairings.push_back(PairOfPlayers(temp[temp.size() - 1]));
}
