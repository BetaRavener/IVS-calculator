/**
 * @file evaulator.cpp
 * @author Tomas Polesovsky, Miroslav Pavelek, Ivan Sevcik, Zdenek Sklenar
 * @brief Layer between GUI and core of application
 */

#include "inc/core/evaluator.h"

Evaluator::Evaluator()
{

}

Evaluator::~Evaluator()
{

}


/**
 * Evaulate input expression
 * @param input expression
 * @return result output expression
*/
double Evaluator::evaluate(std::string input)
{
    TokenVector tokenVector = _scanner.scan(input);
    double result = _parser.parse(tokenVector);
    return result;
}
