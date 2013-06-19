

#include <iostream>
#include <sstream>

#include "parser.h"
#include "production.h"


int main(int argc, char* argv[]) {
	std::istringstream inp("5*4+3*12");

	pratt::Parser p = pratt::Parser(inp);

	pratt::production::Production* result = p.Expression(0);

	std::cout << result->Evaluate() << std::endl;

	return 0;
}
