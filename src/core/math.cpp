/**
 * @file math.cpp
 * @author Tomas Polesovsky, Miroslav Pavelek, Ivan Sevcik, Zdenek Sklenar
 * @brief Mathematical library including primary operations and functions
 */

#include "inc/core/math.h"
#include "inc/core/myexception.h"

/**
 * Adding two numbers
 * @param a first number
 * @param b second number
 * @return result of operation
*/
double Math::add(double a, double b)
{
    return a+b;
}


/**
 * Subtraction of two numbers
 * @param a first number
 * @param b second number
 * @return result of operation
*/
double Math::sub(double a, double b)
{
    return a-b;
}


/**
 * Multiply two numbers
 * @param a first number
 * @param b second number
 * @return result of operation
*/
double Math::mul(double a, double b)
{
    return a*b;
}


/**
 * Divide two numbers
 * @param a first number
 * @param b second number
 * @throw MathException divided by zero
 * @return result of operation
*/
double Math::div(double a, double b)
{
    if (b == 0)
        throw MathException();

    return a/b;
}


/**
 * Squaring number
 * @param x number
 * @param exp exponent
 * @return result of operation
*/
double Math::exp(double x, int exp)
{
    double result = (x == 0) ? 0 : 1;

    for (int i = 0; i < abs(exp); i++){
        result *= x;
    }

    if (exp < 0)
        result = Math::div(1, result);

    return result;
}


/**
 * Absolute value of number
 * @param x number
 * @return result of operation
*/
double Math::abs(double x)
{
    return x < 0.0 ? -x : x;
}


/**
 * The square root of number
 * @param x number
 * @return result of operation
*/
double Math::sqrt(double x)
{
    double eps = 1.0e-15;

    if(x < 0)
        throw MathException();

    double y, nextMem = 1;
    do{
        y = nextMem;
        nextMem = (y + x/y) * 0.5;
    }while(Math::abs(nextMem - y) > Math::abs(eps*y));

    return y;
}


/**
 * Factorial of number
 * @param x number
 * @return result of operation
*/
int Math::fact(int x)
{
    if (x < 0)
        throw MathException();

    int fac = 1;

    for (int i = 1; i <= x; i++){
        fac = fac*i;
    }

    return fac;
}
