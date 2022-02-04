#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "IPlayer.hpp"

namespace mygame {
	class Player final : public IPlayer {
	public:
		Player() = delete;
		Player(std::shared_ptr< IGameBoard > gameBoard);
		~Player() override  = default;
		Player(const Player &) = default;
		Player(Player &&) = default;
		Player &operator=(const Player &) = default;
		Player &operator=(Player &&) = default;

		std::unique_ptr<IPlayer> clone() const override;
	protected:
	private:
	};
}

#endif
