#include "PairOfPlayers.h"

std::string PairOfPlayers::display()
{
    return playerWhite.playerToPairings() + " - " + playerBlack.playerToPairings();
}

std::string PairOfPlayers::displayResult()
{
    return playerWhite.playerToPairings() + " " + gameResult + " " + playerBlack.playerToPairings();
}

PairOfPlayers::PairOfPlayers(Player p1, Player p2) : playerWhite(p1), playerBlack(p2) {

}

PairOfPlayers::PairOfPlayers(Player p1) : playerWhite(p1)
{
    playerBlack = Player("Bye", 0);

}

void PairOfPlayers::setResult(int result){
    switch (result) {
        case(0): {
            gameResult = "1 - 0";
            playerWhite.points++;
            //playerWhite.playersPlayedWith.push_back(std::make_pair(playerBlack.startingPosition, 1));
            break;
        }
        case(1): {
            gameResult = "0.5-0.5";
            playerWhite.points += 0.5;
            playerBlack.points += 0.5;
            break;
        }
        case(2): {
            gameResult = "0 - 1";
            playerBlack.points++;
            break;
        }

    }
}

int PairOfPlayers::getWhitePlayer()
{
    return playerWhite.startingPosition;
}

int PairOfPlayers::getBlackPlayer()
{
    return playerBlack.startingPosition;
}
