#include "inc/core/scanner.h"

Scanner::Scanner()
{

}

Scanner::~Scanner()
{

}

TokenVector Scanner::scan(std::string input)
{
    TokenVector tokenVector;

    //TODO: Finite state automat that scans input and fills tokenVector
    //      Example of adding a new token:
    //          tokenVector.add(new Token(Token::Type::LeftBrace));
    //          tokenVector.add(new NumberToken(10.0));
    //          tokenVector.add(new FunctionToken(FunctionToken::FunctionId::Exponential));
    //      Dynamic allocation is required because of Token inheritance
    //      Items will be deallocated by vector's destructor

    return tokenVector;
}

