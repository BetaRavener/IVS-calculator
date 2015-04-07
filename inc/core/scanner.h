#ifndef SCANNER_H
#define SCANNER_H

#include <vector>
#include <string>
#include "token.h"

class Scanner
{
public:    
    Scanner();
    ~Scanner();

    TokenVector scan(std::string input);
};

#endif // SCANNER_H
