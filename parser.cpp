

#include "parser.h"
#include "token.h"
#include "production.h"


namespace pratt {


Parser::Parser(std::istream& st)
		: lex(st) {
	tk = lex.Get();
}

pratt::production::Production* Parser::Expression(int rbp) {
	pratt::token::Token* last = tk;
	tk = lex.Get();

	pratt::production::Production* left = last->Nud(this);

	while (rbp < tk->Lbp()) {
		delete last;
		last = tk;
		tk = lex.Get();

		left = last->Led(this, left);
	}

	delete last;

	return left;
}


} // namespace pratt
