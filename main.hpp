#ifndef _MAIN_HPP_
#define _MAIN_HPP_

#include <memory>
#include "IGame.hpp"
#include "IGameBoard.hpp"

void readGrid(unsigned char gridSize, std::shared_ptr< mygame::IGameBoard > opponentBoard);
void readShips(unsigned char numOfShips, std::shared_ptr< mygame::IGame > battleShipGame);
void setFastInput();
std::shared_ptr<mygame::IGame> createGame();
int main( int argc, char *argv[] );

#endif
