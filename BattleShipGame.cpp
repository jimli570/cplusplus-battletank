#include "BattleshipGame.hpp"

using namespace mygame;

#include "Ship.hpp"

BattleShipGame::BattleShipGame(std::shared_ptr<IPlayer> opponent) : IGame(opponent)
{
}

std::unique_ptr<IGame> BattleShipGame::clone() const
{
	std::unique_ptr<BattleShipGame> game(new BattleShipGame(*this));

	return game;
}
