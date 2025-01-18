#include "PairOfPlayers.h"

std::string PairOfPlayers::display()
{
    return playerWhite.playerToPairings() + " - " + playerBlack.playerToPairings();
}

PairOfPlayers::PairOfPlayers(Player& p1, Player& p2) : playerWhite(p1), playerBlack(p2) {

}
