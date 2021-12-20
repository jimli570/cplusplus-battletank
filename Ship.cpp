#include "Ship.hpp"

using namespace mygame;

Ship::Ship(unsigned char width, unsigned char height) 
	: IShip(width, height)
{
}

std::unique_ptr<IShip> Ship::clone() const {
	std::unique_ptr<IShip> ship(new Ship(*this));

	return ship;
}

