
#ifndef PRATT_PRODUCTION_H
#define PRATT_PRODUCTION_H


namespace pratt {
namespace production {


class Production {

public:
	virtual int Evaluate() = 0;
};

class Terminal : public Production {

public:
	int Value;

	Terminal(int);

	virtual int Evaluate();
};

class InfixOp : public Production {

public:
	Production* Left;
	Production* Right;

	InfixOp(Production*, Production*);

	~InfixOp() {
		delete Left;
		delete Right;
	}
};

class Mul : public InfixOp {

public:
	Mul(Production*, Production*);

	virtual int Evaluate();
};

class Add : public InfixOp {

public:
	Add(Production*, Production*);

	virtual int Evaluate();
};


}} // namespace pratt::production


#endif
