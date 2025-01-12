#include "Player.h"

Player::Player(std::string sn, std::string n, std::string c, Date bd, int r) {
	surname = sn;
	name = n;
	club = c;
	dateOfBirth = bd;
	rating = r;
	points = 0;
	playersPlayedWith = {};
}

int Player::getRating() {
	return rating;
}

const std::string Player::playerInfo()
{
	return surname + ", " + name;
}

std::string Player::playerToFile()
{
	return surname + ", " + name;
}

//std::ostream& operator<<(std::ostream& os, const Player& player) {
//	os << player.surname << ", " << player.name;
//	return os;
//}