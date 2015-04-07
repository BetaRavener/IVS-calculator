#ifndef PARSER_H
#define PARSER_H

#include "token.h"

class Parser
{
public:
    Parser();
    ~Parser();

    double parse(const TokenVector& tokenVector);
};

#endif // PARSER_H
