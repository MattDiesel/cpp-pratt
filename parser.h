
#ifndef PRATT_PARSER_H
#define PRATT_PARSER_H


#include <istream>

#include "lexer.h"

// #include "production.h"
namespace pratt { namespace production {
	class Production;
}}

// #include "token.h"
namespace pratt { namespace token {
	class Token;
}}

namespace pratt{


class Parser {

public:
	pratt::Lexer lex;
	pratt::token::Token* tk;

	Parser(std::istream&);
	pratt::production::Production* Expression(int);


};


} // namespace pratt


#endif
