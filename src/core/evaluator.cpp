#include "inc/core/evaluator.h"

Evaluator::Evaluator()
{

}

Evaluator::~Evaluator()
{

}



double Evaluator::evaluate(std::string input)
{
    TokenVector tokenVector = _scanner.scan(input);
    double result = _parser.parse(tokenVector);
    return result;
}
