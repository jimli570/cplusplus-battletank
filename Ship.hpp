#ifndef _SHIP_HPP_
#define _SHIP_HPP_

#include "IShip.hpp"

namespace mygame {
	class Ship final: public IShip
	{
	public: 
		Ship() = delete;
		Ship(unsigned char width, unsigned char height);
		virtual ~Ship() = default;
		Ship(const Ship &) = default;
		Ship(Ship &&) = default;
		Ship &operator=(const Ship &) = default;
		Ship &operator=(Ship &&) = default;

		std::unique_ptr<IShip> clone() const override;

	protected:
	private:
	};
}

#endif
