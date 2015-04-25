/**
 * @file evaulator.h
 * @author Tomas Polesovsky, Miroslav Pavelek, Ivan Sevcik, Zdenek Sklenar
 * @brief evaulator evaulator.cpp
 */

#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <string>
#include "scanner.h"
#include "parser.h"

class Evaluator
{
public:
    Evaluator();
    ~Evaluator();

    double evaluate(std::string input);

private:
    Scanner _scanner;
    Parser _parser;
};

#endif // EVALUATOR_H
