#ifndef _IPLAYER_HPP_
#define _IPLAYER_HPP_

#include <memory>
#include <vector>

#include "IGameBoard.hpp"
#include "IShip.hpp"

namespace mygame {

	class IPlayer {
	public:
		IPlayer() = delete;
		IPlayer(std::shared_ptr<IGameBoard> gameBoard) :m_gameBoard(gameBoard) {};
		virtual ~IPlayer() = default;
		IPlayer(const IPlayer& rhs) {
			m_gameBoard = std::move(rhs.getGameBoard()->clone());

			auto placedShips = std::move(rhs.getPlacedShips());
			std::for_each(m_placedShiips.cbegin(), m_placedShiips.cend(), [&](const std::shared_ptr<IShip>& iShip) {
				addPlacedShip(iShip->clone());
			});

			auto availShips = std::move(rhs.getAvailableShips());
			std::for_each(availShips.cbegin(), availShips.cend(), [&](const std::shared_ptr<IShip>& iShip) {
				addShip(iShip->clone());
			});
		};
		IPlayer(IPlayer &&) = default;
		IPlayer &operator=(const IPlayer& rhs) {
			if (this == &rhs) { return *this; }

			m_gameBoard = std::move(rhs.getGameBoard()->clone());

			m_placedShiips.clear();
			auto placedShips = std::move(rhs.getPlacedShips());
			std::for_each(m_placedShiips.cbegin(), m_placedShiips.cend(), [&](const std::shared_ptr<IShip>& iShip) {
				addPlacedShip(iShip->clone());
			});

			m_availableShips.clear();
			auto availShips = std::move(rhs.getAvailableShips());
			std::for_each(availShips.cbegin(), availShips.cend(), [&](const std::shared_ptr<IShip>& iShip) {
				addShip(iShip->clone());
			});

			return *this;
		};
		IPlayer &operator=(IPlayer &&) = default;

		void setGameBoard(std::shared_ptr<IGameBoard> gameBoard) {
			m_gameBoard = gameBoard;
		}

		std::shared_ptr<IGameBoard> getGameBoard() const {
			return m_gameBoard;
		}
		
		bool allShipsPlaced() const {
			return (m_availableShips.size() == 0);
		}

		std::vector< std::shared_ptr<IShip> > getAvailableShips() const {
			return m_availableShips;
		}

		std::vector< std::shared_ptr<IShip> > getPlacedShips() const {
			return m_placedShiips;
		}

		void addShip(const std::shared_ptr<IShip>& iShip) {
			m_availableShips.push_back(iShip);
		}

		bool tryPlaceShip(unsigned char col, unsigned char row, unsigned char shipIndex,
			const std::shared_ptr<IShip>& iShip) {

			bool didPlaceShip = m_gameBoard->tryPlaceShip(col, row, iShip);

			if (didPlaceShip) {
				addPlacedShip(m_availableShips.at(shipIndex));
				removePlacedShip(shipIndex);
			}

			return didPlaceShip;
		}

		virtual std::unique_ptr<IPlayer> clone() const = 0;

	protected:

	private:
		void addPlacedShip(std::shared_ptr<IShip> iShip) {
			m_placedShiips.push_back(iShip);
		}

		void removePlacedShip(unsigned char shipIndex) {
			m_availableShips.erase(m_availableShips.begin() + shipIndex);
		}

		std::shared_ptr<IGameBoard> m_gameBoard;
		std::vector< std::shared_ptr<IShip> > m_availableShips;
		std::vector< std::shared_ptr<IShip> > m_placedShiips;
	};
}  // namespace mygame

#endif
