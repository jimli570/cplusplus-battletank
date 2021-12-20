#include "GameBoard.hpp"

using namespace mygame;

GameBoard::GameBoard(unsigned char sideSize) : IGameBoard(sideSize)
{
}

GameBoard::GameBoard(const std::vector<unsigned char>& fullGrid,
	                 unsigned char sideSize): 
	IGameBoard(fullGrid, sideSize)
{
}

std::unique_ptr<IGameBoard> GameBoard::clone() const {
	std::unique_ptr<IGameBoard> gameBoard(new GameBoard(*this));

	return gameBoard;
}
