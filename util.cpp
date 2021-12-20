#include "util.hpp"

#include <functional>

using namespace mygame::util;

unsigned char mygame::util::getMatrixPos( unsigned char col, unsigned char row,
                                             unsigned char axisDim ) {
  return ( col + row * axisDim );
}

unsigned char mygame::util::asciiIntToValue(unsigned char asciiIntValue) {
	// char '0' = 48, so need to shift -48
	return (asciiIntValue - '0');
}

size_t mygame::util::getHash(const std::string_view stringToHash)
{
	return std::hash<std::string_view>{}(stringToHash);
}
