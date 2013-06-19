
#include <istream>

#include "token.h"
#include "lexer.h"


namespace pratt {


Lexer::Lexer(std::istream& s)
	: st(s) {
}

pratt::token::Token* Lexer::Get() {
	char c = st.peek();

	if (!st)
		return NULL;
	else if (c == '*') {
		st.get();
		return new pratt::token::Mul;
	}
	else if (c == '+') {
		st.get();
		return new pratt::token::Add;
	}
	else {
		int ret;
		st >> ret;

		return new pratt::token::Integer(ret);
	}
}


} // namespace pratt
