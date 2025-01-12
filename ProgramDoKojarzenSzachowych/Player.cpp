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

Player::Player(std::string line){
	size_t start = 0, end = 0;

	// Nazwisko
	end = line.find(',', start);
	//surname = trim(line.substr(start, end - start));
	surname = line.substr(start, end - start);
	start = end + 1;

	// Imiê
	end = line.find(',', start);
	//name = trim(line.substr(start, end - start));
	name = line.substr(start, end - start);
	start = end + 1;


	club = " ";
	dateOfBirth = Date(1, 1, 1);
	rating = 0;
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