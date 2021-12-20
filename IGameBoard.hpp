#ifndef _IGAMEBOARD_HPP_
#define _IGAMEBOARD_HPP_

#include <vector>
#include <algorithm>
#include <memory>
#include <ostream>

#include "util.hpp"
#include "IShip.hpp"

namespace mygame {

	class IGameBoard {
	public:
		IGameBoard() = default;
		IGameBoard(unsigned char sideSize) : m_sideSize(sideSize)
		{
			m_grid.reserve(sideSize * sideSize);
		}

		IGameBoard(const std::vector<unsigned char>& fullGrid, unsigned char sideSize)
			: m_grid(fullGrid), m_sideSize(sideSize)
		{
			m_grid.reserve(sideSize * sideSize);
		}

		virtual ~IGameBoard() = default;
		IGameBoard(const IGameBoard &) = default;
		IGameBoard(IGameBoard &&) = default;
		IGameBoard &operator=(const IGameBoard &) = default;
		IGameBoard &operator=(IGameBoard &&) = default;

		std::vector< unsigned char > getGrid() const {
			return m_grid;
		};

		unsigned char getGridValue(unsigned char col, unsigned char row) const {
			return m_grid.at(util::getMatrixPos(col, row, m_sideSize));
		};

		unsigned char getGridSideSize() const {
			return m_sideSize;
		}

		unsigned char getGridSize() const {
			return (getGridSideSize() * getGridSideSize());
		}

		void addGridData(unsigned char data) {
			m_grid.push_back(data);
		};

		void setGrid(const std::vector<unsigned char>& grid) {
			unsigned char matrixPos = 0;
			std::for_each(grid.cbegin(), grid.cend(),
				[&](unsigned char gridValue) {
				m_grid.at(matrixPos) = gridValue;
				++matrixPos;
			});
		}

		void setGridAt(unsigned char col, unsigned char row, unsigned char value) {
			m_grid.at(util::getMatrixPos(col, row, m_sideSize)) = value;
		};

		bool tryPlaceShip(unsigned char col, unsigned char row, const std::shared_ptr<IShip>& iShip) {
			constexpr unsigned char placedMarker = 'X';

			unsigned char width = iShip->getWidth();
			unsigned char height = iShip->getHeight();

			// Check so ship inside bunds
			if (!isInBounds(col, row, width, height)) { return false; }

			unsigned char matrixPos;
			std::vector< unsigned char > acceptedPositions;

			// Lets go through the battleship, test every position it occupies
			for (unsigned char y = 0; y < height; ++y) {
				for (unsigned char x = 0; x < width; ++x) {
					matrixPos = util::getMatrixPos(col + x, row + y, m_sideSize);

					// Not possible, since we know it is a miss here
					if (m_grid.at(matrixPos) == placedMarker) {
						return false;
					}

					acceptedPositions.push_back(matrixPos);
				}
			}

			// Place 'X' where ship is placed
			placeOnGrid(acceptedPositions, placedMarker);

			return true;
		}

		// Verify so no ships remaining to be found
		bool allShipsFound() const {
			constexpr unsigned char shipRegistred = 'O';

			return
				std::none_of(m_grid.begin(), m_grid.end(), [&](unsigned char gridVal) {
				return (gridVal == shipRegistred);
			});
		}

		virtual std::unique_ptr<IGameBoard> clone() const = 0;

		friend std::ostream& operator<< (std::ostream& o, const IGameBoard& gameBoard) {
			unsigned char counter(0);

			std::for_each(gameBoard.m_grid.begin(), gameBoard.m_grid.end(),
				[&](unsigned char gridValue) {
				if (counter >= gameBoard.m_sideSize) {
					counter = 0;
					o << std::endl;
				}

				o << gridValue;

				++counter;
			});

			return o;
		}

	protected:
	private:
		bool isInBounds(unsigned char col, unsigned char row, unsigned char width, unsigned char height) const {
			bool outOfBounds = ((col + width) > m_sideSize) || ((row + height) > m_sideSize);

			return (!outOfBounds);
		}

		void placeOnGrid(const std::vector< unsigned char >& positions, unsigned char replaceValue) {
			std::for_each(positions.begin(), positions.end(),
				[&](unsigned char pos) {
				m_grid.at(pos) = replaceValue;
			});
		}

		unsigned char m_sideSize;
		std::vector< unsigned char > m_grid;
	};
}  // namespace mygame
#endif
