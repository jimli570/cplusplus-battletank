#ifndef _IGAMEANALYZER_HPP_
#define _IGAMEANALYZER_HPP_

#include "IGame.hpp"

#include <memory>

namespace mygame {
	class IGameAnalyzer
	{
	public:
		IGameAnalyzer() = default;
		virtual ~IGameAnalyzer() = default;
		IGameAnalyzer(const IGameAnalyzer &) = default;
		IGameAnalyzer(IGameAnalyzer &&) = default;
		IGameAnalyzer &operator=(const IGameAnalyzer &) = default;
		IGameAnalyzer &operator=(IGameAnalyzer &&) = default;

		virtual unsigned int analyze(std::shared_ptr< IGame > game) const = 0;

	private:
	protected:
	};
}

#endif
