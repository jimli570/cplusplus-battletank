#include "main.hpp"

#include <iostream>
#include <string>
#include <algorithm>

#include "GameBoard.hpp"
#include "BattleShipGame.hpp"
#include "Ship.hpp"
#include "Player.hpp"

#include "GameAnalyzer.hpp"

using namespace mygame;
using namespace mygame::util;

void readGrid(unsigned char gridSize, std::shared_ptr< IGameBoard > opponentBoard) {
	std::string gridRowData;

	for (unsigned char i = 0; i < gridSize; ++i) {
		std::cin >> gridRowData;

		std::for_each(gridRowData.cbegin(), gridRowData.cend(),
			[&](unsigned char charValue) {
			opponentBoard->addGridData(charValue);
		});
	}
}

void readShips(unsigned char numOfShips, std::shared_ptr<IGame> battleShipGame)
{
	unsigned char shipSize;

	for (unsigned char i = 0; i < numOfShips; ++i) {
		std::cin >> shipSize;
		shipSize = asciiIntToValue(shipSize);

		// Create them horizontally
		std::shared_ptr<IShip> ship(new Ship(shipSize, 1));
		battleShipGame->addShip(ship);
	}
}

std::shared_ptr<IGame> createGame() {
	unsigned char gridSize, numOfShips;

	// Read gridDim, numOfShips
	std::cin >> gridSize >> numOfShips;

	gridSize = asciiIntToValue(gridSize);
	numOfShips = asciiIntToValue(numOfShips);

	std::shared_ptr< IGameBoard > opponentBoard(new GameBoard(gridSize));
	std::shared_ptr< IPlayer > opponentPlayer(new Player(opponentBoard));
	std::shared_ptr< IGame > battleShipGame(new BattleShipGame(opponentPlayer));

	readGrid(gridSize, opponentBoard);
	readShips(numOfShips, battleShipGame);
	battleShipGame->initPlayers(); //< Hand over ships to the opponent

	return battleShipGame;
}

void setFastInput() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
}

int main(int argc, char *argv[]) {
	setFastInput();
	auto battleShipGame = createGame();

	std::cout << *battleShipGame->getOpponent()->getGameBoard() << std::endl << std::endl;

	// Now lets analyze the game and find amount of possible outcomes
	std::unique_ptr<IGameAnalyzer> gameAnalyzer(new GameAnalyzer);
	std::cout << "Total number of combinations: " << gameAnalyzer->analyze(battleShipGame) << std::endl << std::endl;

	return 0;
}
