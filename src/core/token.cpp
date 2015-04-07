#include "inc/core/token.h"

Token::Token(Token::Type type) :
    _type(type)
{

}

Token::~Token()
{

}

Token *Token::clone() const
{
    return new Token(_type);
}


NumberToken::NumberToken(double number) :
    Token(Token::Type::Number),
    _number(number)
{

}

NumberToken::~NumberToken()
{

}

NumberToken *NumberToken::clone() const
{
    return new NumberToken(_number);
}


FunctionToken::FunctionToken(FunctionToken::FunctionId functionId) :
    Token(Token::Type::Function),
    _functionId(functionId)
{

}

FunctionToken::~FunctionToken()
{

}

FunctionToken *FunctionToken::clone() const
{
    return new FunctionToken(_functionId);
}

FunctionToken::FunctionId FunctionToken::getFunctionId()
{
    return _functionId;
}


TokenVector::TokenVector()
{

}

TokenVector::TokenVector(const TokenVector &other)
{
    for (unsigned int i = 0; i < other.size(); i++)
    {
        _tokenVector.push_back(other[i]->clone());
    }
}

TokenVector::~TokenVector()
{
    for (unsigned int i = 0; i < _tokenVector.size(); i++)
    {
        delete _tokenVector[i];
        _tokenVector[i] = nullptr;
    }
}

Token * TokenVector::operator [](std::vector<Token *>::size_type idx) const
{
    return _tokenVector[idx];
}

std::vector<Token *>::size_type TokenVector::size() const
{
    return _tokenVector.size();
}

void TokenVector::add(Token *token)
{
    _tokenVector.push_back(token);
}
