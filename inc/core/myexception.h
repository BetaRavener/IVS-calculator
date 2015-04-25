/**
 * @file myexception.h
 * @author Tomas Polesovsky, Miroslav Pavelek, Ivan Sevcik, Zdenek Sklenar
 * @brief myexception myexception.cpp
 */

#ifndef MYEXCEPTION
#define MYEXCEPTION

#include <stdexcept>

class MathException : std::exception
{

};

class LexicalException : std::exception
{

};

class SyntaxException : std::exception
{

};


#endif // MYEXCEPTION

