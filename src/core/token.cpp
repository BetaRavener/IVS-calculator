#include "inc/core/token.h"

Token::Token(Token::Type type) :
    _type(type),
    _skip(false)
{

}

Token::~Token()
{

}

Token *Token::clone() const
{
    return new Token(_type);
}

Token::Type Token::type() const
{
    return _type;
}

bool Token::skip()
{
    _skip = true;
}

bool Token::isSkipped()
{
    return _skip;
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

double NumberToken::number() const
{
    return _number;
}

void NumberToken::number(double number)
{
    _number = number;
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

FunctionToken::FunctionId FunctionToken::functionId() const
{
    return _functionId;
}

unsigned int FunctionToken::paramNum() const
{
    switch(_functionId)
    {
    case FunctionId::Exponential:
        return 2;
    case FunctionId::Factorial:
        return 1;
    case FunctionId::SquareRoot:
        return 1;
    }
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
