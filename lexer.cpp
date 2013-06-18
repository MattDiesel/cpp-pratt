
#include <istream>

#include "token.h"
#include "lexer.h"


namespace pratt {


Lexer::Lexer(std::istream& s)
	: st(s) {
}

pratt::token::Token* Lexer::Get() {
	char c = st.get();

	if (!st)
		return new pratt::token::Eof;
	else if (c == '*')
		return new pratt::token::Mul;
	else if (c == '+')
		return new pratt::token::Add;
	else
		return new pratt::token::Integer(c - '0');
}


} // namespace pratt
