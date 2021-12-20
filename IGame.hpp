#ifndef _IGAME_HPP_
#define _IGAME_HPP_

#include <memory>
#include <algorithm>
#include <vector>

#include "IPlayer.hpp"
#include "IShip.hpp"

namespace mygame {

	class IGame {
	public:
		IGame() = delete;

		virtual ~IGame() = default;

		IGame(std::shared_ptr<IPlayer> opponent) : m_opponent(opponent) { }

		IGame(const IGame& rhs) {
			m_opponent = std::move(rhs.m_opponent->clone());

			auto ships = std::move(rhs.getGameShips());
			std::for_each(ships.begin(), ships.end(), [&](const std::shared_ptr<IShip> iShip) {
				addShip(iShip->clone());
			});

		};

		IGame(IGame &&) = default;

		IGame &operator=(const IGame& rhs) {
			if (this == &rhs) { return *this; }

			m_opponent = std::move(rhs.m_opponent->clone());

			m_gameShips.clear();
			auto ships = std::move(rhs.getGameShips());
			std::for_each(ships.cbegin(), ships.cend(), [&](const std::shared_ptr<IShip>& iShip) {
				addShip(iShip->clone());
			});

			return *this;
		};

		IGame &operator=(IGame &&) = default;

		virtual std::unique_ptr<IGame> clone() const = 0;

		std::shared_ptr< IPlayer > getOpponent() const {
			return m_opponent;
		}

		void initPlayers() {
			std::for_each(m_gameShips.cbegin(), m_gameShips.cend(),
				[&](const std::shared_ptr<IShip>& iShip) {
				m_opponent->addShip(iShip);
			});
		}

		void setOpponent(const std::shared_ptr<IPlayer>& player) {
			m_opponent = player;
		}


		void addShip(const std::shared_ptr<IShip>& iShip) {
			m_gameShips.push_back(iShip);
		}

	protected:
	private:

		std::vector< std::shared_ptr<IShip> > getGameShips() const {
			return m_gameShips;
		}

		std::shared_ptr< IPlayer > m_opponent;
		std::vector< std::shared_ptr<IShip> > m_gameShips;
	};
}  // namespace mygame

#endif
