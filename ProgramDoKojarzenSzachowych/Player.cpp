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

	//nr startowy
	end = line.find(',', start);
	startingPosition = std::stoi(line.substr(start, end - start));
	start = end + 1;

	// Nazwisko
	end = line.find(',', start);
	surname = line.substr(start, end - start);
	start = end + 1;

	// Imiê
	end = line.find(',', start);
	name = line.substr(start, end - start);
	start = end + 1;

	// klub
	end = line.find(',', start);
	club = line.substr(start, end - start);
	start = end + 1;

	// Rating
	end = line.find(',', start);
	rating = std::stoi(line.substr(start, end - start));
	start = end + 1;

	// data
	end = line.find(',', start);
	dateOfBirth = Date(line.substr(start, end - start));
	start = end + 1;

	points = 0;
	playersPlayedWith = {};
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
	const int posWidth = 5;         // Szerokoœæ dla numeru startowego
	const int surnameWidth = 17;   // Szerokoœæ dla nazwiska
	const int nameWidth = 17;      // Szerokoœæ dla imienia
	const int clubWidth = 17;      // Szerokoœæ dla klubu
	const int ratingWidth = 7;      // Szerokoœæ dla klubu

	// Numer
	stream << std::setw(posWidth) << std::left << (std::to_string(startingPosition) + ".");

	// ranking
	stream << std::setw(ratingWidth) << std::left << (std::to_string(rating));

	// Nazwisko
	stream << std::setw(surnameWidth) << std::left << surname;

	// Imiê
	stream << std::setw(nameWidth) << std::left << name;

	// klub
	stream << std::setw(clubWidth) << std::left << club;

	

	stream << dateOfBirth.getYear();

	return stream.str();
}

std::string Player::playerToFile()
{
	return std::to_string(startingPosition) +"," + surname + "," + name + ","+club+"," + std::to_string(rating)+"," + dateOfBirth.writeDate();
}

std::string Player::playerToPairings()
{
	std::ostringstream oss;
	oss << surname << ", " << name << "["<< std::fixed << std::setprecision(1) << points << "]";
	return oss.str();
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

	//buch
	stream << std::fixed << std::setprecision(1);
	stream << std::setw(posWidth) << std::left << buch;

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

bool Player::comparePlayersByStarting(const Player& p1, const Player& p2)
{
	return p1.startingPosition < p2.startingPosition;
}

void Player::sortByStarting(std::vector<Player>& startingList)
{
	std::sort(startingList.begin(), startingList.end(), comparePlayersByStarting);
}

void Player::setBuch(std::vector<Player>  listOfPlayers){
	buch = 0;
	for (auto& game : playersPlayedWith) {
		if (game.second == 1) {
			buch += listOfPlayers[game.first-1].points;
		}
	}
}

double Player::getBuch() const
{
	return buch;
}
