#ifndef _GAMEANALYZER_HPP_
#define _GAMEANALYZER_HPP_

#include "IGameAnalyzer.hpp"

#include <memory>
#include <vector>

#include "IGame.hpp"
#include "IShip.hpp"
#include "IPlayer.hpp"

namespace mygame {

	class GameAnalyzer final : public IGameAnalyzer
	{

	public:
		GameAnalyzer() = default;
		virtual ~GameAnalyzer() = default;
		GameAnalyzer(const GameAnalyzer &) = default;
		GameAnalyzer(GameAnalyzer &&) = default;
		GameAnalyzer &operator=(const GameAnalyzer &) = default;
		GameAnalyzer &operator=(GameAnalyzer &&) = default;

		unsigned int analyze(std::shared_ptr< IGame > game) const override;

	protected:
	private:

		struct CacheData {
			bool canPlace;
			std::vector<unsigned char> placedGrid;
		};

		struct Position {
			Position(const Position& pos)
				: matrixPos(pos.matrixPos), col(pos.col), row(pos.row)
			{};
			Position(unsigned char m, unsigned char c, unsigned char r)
				: matrixPos(m), col(c), row(r)
			{};

			unsigned char matrixPos;
			unsigned char col;
			unsigned char row;
		};

		unsigned int dfs(
			Position nodeStartPosition,
			std::shared_ptr< IPlayer > player
		) const;

		bool isValidLeaf(const std::shared_ptr<IPlayer>& player) const;
		std::vector<std::shared_ptr<IShip>> getShipWithRotations(const std::shared_ptr<IShip>& iShip) const;
	};
}

#endif
