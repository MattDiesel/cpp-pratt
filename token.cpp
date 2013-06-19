
#include "parser.h"
#include "production.h"

#include "token.h"


namespace pratt {
namespace token {


// class Token

pratt::production::Production* Token::Nud(pratt::Parser* p) {
	throw "Nud.";
}

pratt::production::Production* Token::Led(pratt::Parser* p, pratt::production::Production* lhs) {
	throw "Led.";
}

int Token::Lbp() {
	return 0;
}


// class Integer

Integer::Integer(int v)
		: Value(v) {
}

pratt::production::Production* Integer::Nud(Parser* p) {
	return new pratt::production::Terminal(Value);
}

// class InfixOp
// template methods are in header

// class Add

pratt::production::Production* Add::Nud(pratt::Parser* p) {
	return new pratt::production::Add(
			new pratt::production::Terminal(0), 
			p->Expression(pratt::BP_Unary));
}

// class Sub

pratt::production::Production* Sub::Nud(pratt::Parser* p) {
	return new pratt::production::Sub(
			new pratt::production::Terminal(0), 
			p->Expression(pratt::BP_Unary));
}



}} // namespace pratt::token
