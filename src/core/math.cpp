#include "inc/core/math.h"
#include "inc/core/myexception.h"

double Math::add(double a, double b)
{
    return a+b;
}


double Math::sub(double a, double b)
{
    return a-b;
}


double Math::mul(double a, double b)
{
    return a*b;
}


double Math::div(double a, double b)
{
    if (b == 0)
        throw MathException();

    return a/b;
}


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

double Math::abs(double x)
{
    return x < 0.0 ? -x : x;
}

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
