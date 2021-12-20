#ifndef _BATTLESHIP_GAME_
#define _BATTLESHIP_GAME_

#include "IGame.hpp"

#include <memory>

#include "IGameBoard.hpp"

namespace problem_b {

	class BattleShipGame final : public IGame {
	public:
		BattleShipGame() = delete;
		BattleShipGame(std::shared_ptr< problem_b::IGameBoard > gameBoard);
		virtual ~BattleShipGame() = default;
		BattleShipGame(BattleShipGame &) = default;
		BattleShipGame(BattleShipGame &&) = default;
		BattleShipGame &operator=(const BattleShipGame &) = default;
		BattleShipGame &operator=(BattleShipGame &&) = default;

	protected:
	private:
	};

}  // namespace problem_b

#endif
