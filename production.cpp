
#include "production.h"


namespace pratt {
namespace production {


// class Production


// class Terminal

Terminal::Terminal(int v)
		: Value(v) {
}

int Terminal::Evaluate() {
	return Value;
}


// class InfixOp

InfixOp::InfixOp(Production* lhs, Production* rhs) 
		: Left(lhs), Right (rhs) {
}


// class Mul

Mul::Mul(Production* lhs, Production* rhs)
		: InfixOp(lhs, rhs) {
}

int Mul::Evaluate() {
	return Left->Evaluate() * Right->Evaluate();
}


// class Div

Div::Div(Production* lhs, Production* rhs)
		: InfixOp(lhs, rhs) {
}

int Div::Evaluate() {
	return Left->Evaluate() / Right->Evaluate();
}


// class Add

Add::Add(Production* lhs, Production* rhs)
		: InfixOp(lhs, rhs) {
}

int Add::Evaluate() {
	return Left->Evaluate() + Right->Evaluate();
}


// class Sub

Sub::Sub(Production* lhs, Production* rhs)
		: InfixOp(lhs, rhs) {
}

int Sub::Evaluate() {
	return Left->Evaluate() - Right->Evaluate();
}


}} // namespace pratt::production