#include "Player.hpp"

using namespace mygame;

Player::Player(std::shared_ptr<IGameBoard> gameBoard)
	: IPlayer(gameBoard)
{}

std::unique_ptr<IPlayer> Player::clone() const {
	std::unique_ptr<IPlayer> player(new Player(*this));

	return player;
}
