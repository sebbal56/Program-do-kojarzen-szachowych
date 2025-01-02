#include "Tournament.h"

Tournament::Tournament(std::string name, Date date, std::string place, std::string arbiter, std::string about) {
	tournamentName = name;
	tournamentDate = date;
	tournamentArbiter = arbiter;
	tournamentPlace = place;
	tournamentAbout = about;
	std::vector<Player> listOfPlayers = {};
}

std::string Tournament::getName() {
	return tournamentName;
}
std::string Tournament::getPlace() {
	return tournamentPlace;
}
std::string Tournament::getArbiter() {
	return tournamentArbiter;
}
std::string Tournament::getAbout() {
	return tournamentAbout;
}
Date Tournament::getDate() {
	return tournamentDate;
}

void Tournament::addPlayerToList(Player p) {
	if (listOfPlayers.size() == 0) {
		p.startingPosition = 1;
		listOfPlayers.push_back(p);
		return;
	}
	for (int i = 0; i < listOfPlayers.size(); i++) {
		if (listOfPlayers[i].getRating() < p.getRating()) {
			p.startingPosition = i + 1;
			listOfPlayers.insert(listOfPlayers.begin() + i, p);
			for (int j = i; j < listOfPlayers.size(); j++) {
				listOfPlayers[j].startingPosition++;
			}
			return;
		}
	}
}