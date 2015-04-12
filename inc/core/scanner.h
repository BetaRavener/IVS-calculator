#ifndef SCANNER_H
#define SCANNER_H

#include <vector>
#include <string>
#include <stdexcept>

#include "token.h"

class Scanner
{
public:

    Scanner();
    ~Scanner();

    TokenVector scan(std::string input);

private:
    enum State { ST_Function, ST_Number, ST_Double, ST_DoubleDec, ST_Empty, ST_Exit };

};

#endif // SCANNER_H
