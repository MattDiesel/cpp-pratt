
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


enum Precedence {
	BP_Assignment = 100,
	BP_Or = 200,
	BP_And = 300,
	BP_Equality = 400,
	BP_Relational = 500,
	BP_Additive = 600,
	BP_Multiplicative = 700,
	BP_Exponential = 800,
	BP_Unary = 900,
	BP_Primary = 1000
};


class Parser {

public:
	pratt::Lexer lex;
	pratt::token::Token* tk;

	Parser(std::istream&);
	pratt::production::Production* Expression(int);

	~Parser();
};


} // namespace pratt


#endif
