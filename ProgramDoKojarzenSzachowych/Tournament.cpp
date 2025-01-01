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