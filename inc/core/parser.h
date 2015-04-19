#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include <cstdint>
#include <vector>

class Parser
{
public:
    Parser();
    ~Parser();

    double parse(TokenVector& tokenVector);

private:
    class ExprToken
    {
    public:
        enum class Type {Terminal, NonTerminal};

        ExprToken();
        ExprToken(Type type, const Token *token = nullptr);

        Type type() const;
        void setType(Type type);

        const Token *token() const;
        void setToken(const Token *token);

        bool check(Type type, Token::Type tokenType);

        double val() const;
        void setVal(double val);

    private:
        Type _type;
        const Token* _token;

        double _val;
    };

    ExprToken *performOperation(ExprToken* operation, ExprToken *op1, ExprToken *op2);
    ExprToken *performFunction(ExprToken* function, std::vector<ExprToken *> params);
    void reduce(ExprToken* topTerm);
    void reduceMultiparamFunc(uint32_t stackPos, uint32_t *paramCount);
    ExprToken *findTopmostTerminal();
    void deallocateVector();
    void vectorPopN(unsigned int n);

    std::vector<ExprToken *> exprVector;

};

#endif // PARSER_H
