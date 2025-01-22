#include "Tournament.h"
#include "Round.h"

Tournament::Tournament(std::string name, Date date, std::string place, std::string arbiter, std::string about) {
	tournamentName = name;
	tournamentDate = date;
	tournamentArbiter = arbiter;
	tournamentPlace = place;
	tournamentAbout = about;
	std::vector<Player> listOfPlayers = {};
	rounds = {};
	rounds.push_back(Round());
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

bool Tournament::comparePlayersByRating(const Player& p1, const Player& p2)
{
	if (p1.getRating() != p2.getRating()) {
		return p1.getRating() > p2.getRating();
	}
	if (p1.getSurname() != p2.getSurname()) {
		return p1.getSurname() < p2.getSurname();
	}
	return p1.getName() < p2.getName();
}

bool Tournament::comparePlayersByPoints(const Player& p1, const Player& p2)
{
	if (p1.points != p2.points) {
		return p1.points > p2.points;
	}
	if (p1.getSurname() != p2.getSurname()) {
		return p1.getSurname() < p2.getSurname();
	}
	return p1.getName() < p2.getName();
}

bool Tournament::comparePlayersByStarting(const Player& p1, const Player& p2)
{
	return p1.startingPosition < p2.startingPosition;
}

void Tournament::sortByRating(std::vector<Player>& startingList){
	std::sort(startingList.begin(), startingList.end(), comparePlayersByRating);
	for (int i = 0; i < startingList.size(); i++) {
		startingList[i].startingPosition = i + 1;
	}
}

void Tournament::sortByPoints(std::vector<Player>& startingList)
{
	std::sort(startingList.begin(), startingList.end(), comparePlayersByPoints);
}

void Tournament::sortByStarting(std::vector<Player>& startingList)
{
	std::sort(startingList.begin(), startingList.end(), comparePlayersByStarting);
}
