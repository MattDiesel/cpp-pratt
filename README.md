cpp-pratt
=========

This is an example of making a Top Down Operator Precedence (Pratt's) parser in C++. This style of parser is designed to make working with infix operators very easy.

I'm not very good at explaining, so I recommend the following resources:

* http://effbot.org/zone/simple-top-down-parsing.htm
* http://journal.stuffwithstuff.com/2011/03/19/pratt-parsers-expression-parsing-made-easy/
* http://javascript.crockford.com/tdop/tdop.html


I use a parser to test the features of a language I am learning. I've done equivalent parsers in C#, Go, AutoIt, C and D. As a comparison against these other languages, C++ was complex as a language. It's main drawback was that it still uses the horribly outdated approach of a pre-processor #include. For this project (which is pretty small) I had to figure out various problems with circular dependencies and templates - the latter of which it turns out the solution is to write the code in the header file.


Quick explanation
-----------------


The basic structure is as follows:

1) The lexer generated tokens from the input string
2) If the token appears at the beginning of an expression then it's Nud method is called. If it appears infix then Led is called instead with the current left hand side as an argument.
3) Expression parsing ends when the tokens precedence is less than the expressions.
4) Productions are returned, which point to other productions making an AST.
5) The AST is evaluated. 

So in the expression 4+5*3, the following is what the call stack looks like (roughly):

The following is done:

    Expression(0)
        4.Nud()
        +.Led(4)
            Expression(+.Lbp)
                5.Nud()
                *.Led(5)
                    Expression(*.Lbp)
                        3.Nud()

And if you switch the order of operators to 4*5+3 the call stack looks something like:

    Expression(0)
        4.Nud()
        *.Led(4)
            Expression(*.Lbp)
                5.Nud()
        +.Led(4*5)
            Expression(+.Lbp)
                3.Nud()