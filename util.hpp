#ifndef _UTIL_HPP_
#define _UTIL_HPP_

#include <string_view>

namespace mygame::util {

unsigned char getMatrixPos( unsigned char col, unsigned char row,
                            unsigned char axisDim );

unsigned char asciiIntToValue( unsigned char asciiIntValue );

size_t getHash(const std::string_view stringToHash);

}  // namespace mygame::util

#endif
