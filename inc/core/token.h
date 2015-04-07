#ifndef TOKEN_H
#define TOKEN_H

#include <vector>

class Token
{
public:
    enum class Type { Number, Function, LeftBrace, RightBrace, Comma,
                      Plus, Minus, Multiply, Divide };

    Token(Type type);
    virtual ~Token();

    virtual Token* clone() const;

    Type getType();

private:
    Type _type;
};

class NumberToken : public Token
{
public:
    NumberToken(double number);
    virtual ~NumberToken();

    virtual NumberToken* clone() const;

private:
    double _number;
};

class FunctionToken : public Token
{
public:
    enum class FunctionId { Exponential, SquareRoot, Factorial };

    FunctionToken(FunctionId functionId);
    virtual ~FunctionToken();

    virtual FunctionToken* clone() const;

    FunctionId getFunctionId();

private:
    FunctionId _functionId;
};

class TokenVector
{
public:
    TokenVector();
    TokenVector(const TokenVector& other);
    ~TokenVector();

    Token* operator [] (std::vector<Token *>::size_type idx) const;
    std::vector<Token *>::size_type size() const;
    void add(Token* token);

private:
    std::vector<Token *> _tokenVector;
};

#endif // TOKEN_H
