#include "GameAnalyzer.hpp"

#include <algorithm>

#include "IGameBoard.hpp"

using namespace mygame;
using namespace mygame::util;

unsigned int GameAnalyzer::analyze(std::shared_ptr< IGame > game) const
{
	Position currentPosition(0, 0, 0);

	return dfs(currentPosition, game->getOpponent());
}

unsigned int GameAnalyzer::dfs(
	Position nodeStartPosition,
	std::shared_ptr< IPlayer > player
) const {
	unsigned int numOfLeaves = { 0 };
	auto gridSideSize = player->getGameBoard()->getGridSideSize();
	auto gridSize = gridSideSize * gridSideSize;
	auto ships = std::move(player->getAvailableShips());

	bool didPlaceShip, validLeaf, rowChange;
	std::shared_ptr<IPlayer> currentPlayer;

	Position currentPosition(nodeStartPosition);

	for (; currentPosition.matrixPos < gridSize; ++currentPosition.matrixPos) {
		unsigned char uniqueShipIndex = { 0 };

		for (auto uniqueShip = ships.begin(); uniqueShip != ships.end(); ++uniqueShip, ++uniqueShipIndex) {
			for (auto rotatedShip : getShipWithRotations(*uniqueShip)) {
				currentPlayer = std::move(player->clone());

				didPlaceShip = currentPlayer->tryPlaceShip(
					currentPosition.col, currentPosition.row, uniqueShipIndex, rotatedShip);

				if (didPlaceShip) {
					validLeaf = isValidLeaf(currentPlayer);
					numOfLeaves += validLeaf ? 1 : dfs(currentPosition, currentPlayer);
				}
			}
		}

		// Update row & col position
		rowChange = ((currentPosition.col + 1) >= gridSideSize);
		if (rowChange) { currentPosition.col = 0; currentPosition.row += 1; }
		else { ++currentPosition.col; }
	}

	return numOfLeaves;
}

bool GameAnalyzer::isValidLeaf(const std::shared_ptr<IPlayer>& player) const
{
	bool isValidLeaf = false;

	if (player->allShipsPlaced()) {
		isValidLeaf = player->getGameBoard()->allShipsFound();
	}

	return isValidLeaf;
}

std::vector<std::shared_ptr<IShip>> GameAnalyzer::getShipWithRotations(const std::shared_ptr<IShip>& iShip) const {

	std::vector<std::shared_ptr<IShip>> shipsWithOrientation;
	const auto createClone = [&]() { shipsWithOrientation.push_back(iShip->clone()); };
	bool needRotation = (iShip->getMaxSize() > 1);

	createClone();

	if (needRotation) {
		createClone();
		shipsWithOrientation.back()->rotate();
	}

	return shipsWithOrientation;
}
