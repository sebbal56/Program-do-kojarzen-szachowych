#include "Player.h"

int Player::nextStartingNumber = 1;

Player::Player(std::string sn, std::string n, std::string c, Date bd, int r) {
	surname = sn;
	name = n;
	club = c;
	dateOfBirth = bd;
	rating = r;
	points = 0;
	playersPlayedWith = {};
	startingPosition = nextStartingNumber++;
}

Player::Player(std::string line){
	size_t start = 0, end = 0;

	// Nazwisko
	end = line.find(',', start);
	surname = line.substr(start, end - start);
	start = end + 1;

	// Imiê
	end = line.find(',', start);
	name = line.substr(start, end - start);
	start = end + 1;

	// Rating
	end = line.find(',', start);
	rating = std::stoi(line.substr(start, end - start));
	start = end + 1;


	club = " ";
	dateOfBirth = Date(1, 1, 1);
	points = 0;
	playersPlayedWith = {};
	startingPosition = nextStartingNumber++;
}

Player::Player(std::string pauza, int code)
{
	startingPosition = -1;
	surname = "BYE";
	name = "PAUZA";
}

int Player::getRating() const{
	return rating;
}

std::string Player::getSurname() const
{
	return surname;
}

std::string Player::getName() const
{
	return name;
}

const std::string Player::playerInfo(){
	std::ostringstream stream;
	const int posWidth = 4;         // Szerokoœæ dla numeru startowego
	const int surnameWidth = 20;   // Szerokoœæ dla nazwiska
	const int nameWidth = 15;      // Szerokoœæ dla imienia

	// Numer startowy z kropk¹
	stream << std::setw(posWidth) << std::left << (std::to_string(startingPosition) + ".");

	// Nazwisko (bez przecinka)
	stream << std::setw(surnameWidth) << std::left << surname;

	// Imiê (zaraz za nazwiskiem, wyrównane)
	stream << std::setw(nameWidth) << std::left << name;

	// Ocena
	stream << rating;

	return stream.str();
}

std::string Player::playerToFile()
{
	return surname + "," + name + "," + std::to_string(rating);
}

std::string Player::playerToPairings()
{
	return surname + ", " +name;
}

std::string Player::playerToResults(int i)
{
	std::ostringstream stream;
	const int posWidth = 4;         // Szerokoœæ dla numeru startowego
	const int surnameWidth = 20;   // Szerokoœæ dla nazwiska
	const int nameWidth = 15;      // Szerokoœæ dla imienia

	//miejsce
	stream << std::setw(posWidth) << std::left << (std::to_string(i) + ".");

	// punkty
	stream << std::fixed << std::setprecision(1);
	stream << std::setw(posWidth) << std::left << points;

	// Nazwisko (bez przecinka)
	stream << std::setw(surnameWidth) << std::left << surname;

	// Imiê (zaraz za nazwiskiem, wyrównane)
	stream << std::setw(nameWidth) << std::left << name;

	// Ocena
	stream << rating;

	return stream.str();
}

void Player::addAsPlayedWith(int i, double result){
	playersPlayedWith.push_back(std::make_pair(i, result));
}

bool Player::hasntPlayedWith(int n)
{
	for(int i = 0; i < playersPlayedWith.size(); i++){
		if(playersPlayedWith[i].first == n) return false;
	}
	return true;
}

//std::ostream& operator<<(std::ostream& os, const Player& player) {
//	os << player.surname << ", " << player.name;
//	return os;
//}

bool Player::comparePlayersByStarting(const Player& p1, const Player& p2)
{
	return p1.startingPosition < p2.startingPosition;
}

void Player::sortByStarting(std::vector<Player>& startingList)
{
	std::sort(startingList.begin(), startingList.end(), comparePlayersByStarting);
}