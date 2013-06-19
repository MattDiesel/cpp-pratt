

#ifndef PRATT_TOKEN_H
#define PRATT_TOKEN_H


#include "parser.h"
#include "production.h"


namespace pratt {
namespace token {


class Token {

public:
	virtual pratt::production::Production* Nud(pratt::Parser*);
	virtual pratt::production::Production* Led(pratt::Parser*, pratt::production::Production*);
	virtual int Lbp();
};


class Integer : public Token {

public:
	int Value;

	Integer(int);

	virtual pratt::production::Production* Nud(pratt::Parser*);
};

template<class P, int lbp> // Result production, Precedence
class InfixOp : public Token {

public:
	virtual pratt::production::Production*
			Led(pratt::Parser* p, pratt::production::Production* lhs) {
		return new P(lhs, p->Expression(this->Lbp()));
	}

	virtual int Lbp() {
		return lbp;
	}
};

typedef InfixOp<pratt::production::Mul, pratt::BP_Multiplicative> Mul;
typedef InfixOp<pratt::production::Div, pratt::BP_Multiplicative> Div;

class Add : public InfixOp<pratt::production::Add, pratt::BP_Additive> {

public:
	virtual pratt::production::Production* Nud(pratt::Parser*);
};

class Sub : public InfixOp<pratt::production::Sub, pratt::BP_Additive> {

public:
	virtual pratt::production::Production* Nud(pratt::Parser*);
};


}} // namespace pratt::token


#endif
