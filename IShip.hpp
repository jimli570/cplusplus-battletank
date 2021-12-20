#ifndef _ISHIP_HPP_
#define _ISHIP_HPP_

#include <utility>
#include <algorithm>
#include <memory>

namespace mygame {

	class IShip
	{
	public:
		IShip() = delete;
		IShip(unsigned char width, unsigned char height)
			: m_width(width), m_height(height) {};
		virtual ~IShip() = default;
		IShip(const IShip &) = default;
		IShip(IShip &&) = default;
		IShip& operator=(const IShip &) = default;
		IShip& operator=(IShip &&) = default;

		virtual std::unique_ptr<IShip> clone() const = 0;

		std::pair<unsigned char, unsigned char> getSize() const {
			return std::pair<unsigned char, unsigned char>(m_width, m_height);
		}

		unsigned char getWidth() const {
			return m_width;
		}

		unsigned char getHeight() const {
			return m_height;
		}

		void rotate() {
			std::swap(m_width, m_height);
		}

		unsigned char getMaxSize() const {
			return std::max(m_width, m_height);
		}

	protected:

	private:
		unsigned char m_width, m_height;
	};

}

#endif