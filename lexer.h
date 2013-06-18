
#ifndef PRATT_LEXER_H
#define PRATT_LEXER_H


#include <istream>

// #include "token.h"
namespace pratt { namespace token {
	class Token;
}}


namespace pratt {


class Lexer {

public:
	std::istream& st;

	Lexer(std::istream&);
	pratt::token::Token* Get();
};


} // namespace pratt


#endif