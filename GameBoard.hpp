#ifndef _GAMEBOARD_HPP_
#define _GAMEBOARD_HPP_

#include "IGameBoard.hpp"

namespace mygame {
	class GameBoard final : public IGameBoard {
	public:
		GameBoard() = delete;
		GameBoard(unsigned char sideSize);
		GameBoard(const std::vector<unsigned char>& fullGrid, unsigned char sideSize);
		~GameBoard() override = default;
		GameBoard(const GameBoard &) = default;
		GameBoard(GameBoard &&) = default;
		GameBoard &operator=(const GameBoard &) = default;
		GameBoard &operator=(GameBoard &&) = default;

		virtual std::unique_ptr<IGameBoard> clone() const override;

	protected:
	private:
	};
}  // namespace mygame

#endif
