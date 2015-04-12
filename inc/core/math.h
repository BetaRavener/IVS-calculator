#ifndef MATH_H
#define MATH_H

#include <stdexcept>

class Math
{
public:
    static double add(double a, double b);
    static double sub(double a, double b);
    static double mul(double a, double b);
    static double div(double a, double b);
    static double exp(double x, int exp);
    static double sqrt(double x);
    static int fact(int x);
};

#endif // MATH_H
