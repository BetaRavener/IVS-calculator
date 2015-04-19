#include "inc/core/parser.h"
#include "inc/core/token.h"

#include <stdexcept>

#include "inc/core/math.h"
#include "inc/core/myexception.h"

Parser::Parser()
{

}

Parser::~Parser()
{

}

typedef enum
{
    Low,        ///< Token on the top of the stack has lower priority than input token
    High,       ///< Token on the top of the stack has higher priority than input token
    Equal,      ///< Token on the top of the stack has same priority as input token
    Error       ///< Token on the top of the stack cannot be followed by input token, syntax error
} TokenPrecedence;

static uint8_t precedenceTable[(uint32_t)Token::Type::End + 1][(uint32_t)Token::Type::End + 1] =
{
//    num     func    (       )       ,       +       -       *       /      ^      $
    { Error,  Error,  Error,  High,   High,   High,   High,   High,   High,  High,  High  },  // num
    { Error,  Error,  Equal,  Error,  Error,  Error,  Error,  Error,  Error, Error, Error },  // func
    { Low,    Low,    Low,    Equal,  Equal,  Low,    Low,    Low,    Low,   Low,   Error },  // (
    { Error,  Error,  Error,  High,   High,   High,   High,   High,   High,  High,  High  },  // )
    { Low,    Low,    Low,    Equal,  Equal,  Low,    Low,    Low,    Low,   Low,   Error },  // ,
    { Low,    Low,    Low,    High,   High,   High,   High,   Low,    Low,   Low,   High  },  // +
    { Low,    Low,    Low,    High,   High,   High,   High,   Low,    Low,   Low,   High  },  // -
    { Low,    Low,    Low,    High,   High,   High,   High,   High,   High,  Low,   High  },  // *
    { Low,    Low,    Low,    High,   High,   High,   High,   High,   High,  Low,   High  },  // /
    { Low,    Low,    Low,    High,   High,   High,   High,   High,   High,  High,  High  },  // ^
    { Low,    Low,    Low,    Error,  Error,  Low,    Low,    Low,    Low,   Low,   Error },  // $
};

double Parser::parse(TokenVector &tokenVector)
{
    exprVector.clear();
    Token endToken(Token::Type::End);
    ExprToken stackBeginToken(ExprToken::Type::Terminal, &endToken);

    // Find unary "-" and reduce them
    for (int i = 0; i < tokenVector.size() - 1; i++)
    {
        Token* t = tokenVector[i];
        Token* n = tokenVector[i+1];
        if (t->type() == Token::Type::Minus && n->type() == Token::Type::Number)
        {
            bool unite = false;
            if (i == 0)
            {
                unite = true;
            }
            else
            {
                Token *p = tokenVector[i-1];
                switch(p->type())
                {
                case Token::Type::Number:
                case Token::Type::RightBrace:
                    break;
                default:
                    unite = true;
                }
            }

            if (unite)
            {
                t->skip();
                NumberToken *nt = static_cast<NumberToken*>(n);
                nt->number(nt->number() * -1.0);
            }
        }
    }

    uint32_t tokenIdx = 0;
    Token *currentToken = nullptr;
    for (;tokenIdx < tokenVector.size(); tokenIdx++)
    {
        if (!tokenVector[tokenIdx]->isSkipped())
        {
            currentToken = tokenVector[tokenIdx];
            break;
        }
    }

    if (currentToken == nullptr)
        throw SyntaxException();

    while(true)
    {
        ExprToken *topToken = findTopmostTerminal();

        // no terminal found
        if (topToken == nullptr) {
            // there is just one non-terminal on the stack, we succeeded
            if (currentToken->type() == Token::Type::End && exprVector.size() == 1) {
                ExprToken *expr = exprVector.back();
                return expr->val();
            }

            topToken = &stackBeginToken;
        }

        switch (precedenceTable[(uint32_t)topToken->token()->type()][(uint32_t)currentToken->type()]) {
            case Low:
            case Equal: {
                exprVector.push_back(new ExprToken(ExprToken::Type::Terminal, currentToken));
                break;
            }
            case High:
                reduce(topToken);
                continue;

            case Error:
                deallocateVector();
                throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
        }

        while (tokenIdx + 1 < tokenVector.size())
        {
            currentToken = tokenVector[++tokenIdx];
            if (!currentToken->isSkipped())
                break;
        }
    }

    deallocateVector();
    throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
}

Parser::ExprToken *Parser::performOperation(Parser::ExprToken *operation, Parser::ExprToken *op1, Parser::ExprToken *op2)
{
    ExprToken *result = new ExprToken(ExprToken::Type::NonTerminal);

    double x;
    switch(operation->token()->type())
    {
    case Token::Type::Plus:
        x = Math::add(op1->val(), op2->val());
        result->setVal(x);
        break;
    case Token::Type::Minus:
        x = Math::sub(op1->val(), op2->val());
        result->setVal(x);
        break;
    case Token::Type::Multiply:
        x = Math::mul(op1->val(), op2->val());
        result->setVal(x);
        break;
    case Token::Type::Divide:
        x = Math::div(op1->val(), op2->val());
        result->setVal(x);
        break;
    case Token::Type::Exp:
        x = Math::exp(op1->val(), op2->val());
        result->setVal(x);
        break;
    default:
        return nullptr;
    }

    return result;
}

Parser::ExprToken *Parser::performFunction(Parser::ExprToken *function, std::vector<ExprToken *> params)
{
    // Check token type
    if (function->token()->type() != Token::Type::Function)
        return nullptr;

    const FunctionToken *funcToken = static_cast<const FunctionToken*>(function->token());

    // Check number of params
    if (funcToken->paramNum() != params.size())
        return nullptr;

    ExprToken *result = new ExprToken(ExprToken::Type::NonTerminal);

    double x;
    switch(funcToken->functionId())
    {
    case FunctionToken::FunctionId::Exponential:
        x = Math::exp(params[0]->val(), params[1]->val());
        result->setVal(x);
        break;
    case FunctionToken::FunctionId::Factorial:
        x = Math::fact(params[0]->val());
        result->setVal(x);
        break;
    case FunctionToken::FunctionId::SquareRoot:
        x = Math::sqrt(params[0]->val());
        result->setVal(x);
        break;
    default:
        return nullptr;
    }

    return result;
}

void Parser::reduce(Parser::ExprToken *topTerm)
{
    switch (topTerm->token()->type()) {
    case Token::Type::Number:{
        topTerm->setType(ExprToken::Type::NonTerminal);
        const NumberToken* numberToken = static_cast<const NumberToken*>(topTerm->token());
        topTerm->setVal(numberToken->number());
        break;
    }

    case Token::Type::Plus:
    case Token::Type::Minus:
    case Token::Type::Multiply:
    case Token::Type::Divide:
    case Token::Type::Exp: {
        uint32_t stackSize = exprVector.size();
        if (stackSize < 3) {
            deallocateVector();
            throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
        }

        ExprToken* operand2 = *(exprVector.end() - 1);
        if (operand2->type() != ExprToken::Type::NonTerminal) {
            deallocateVector();
            throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
        }

        ExprToken* operation = *(exprVector.end() - 2);
        if (operation != topTerm)
            throw SyntaxException(); //throw new std::runtime_error("Syntax Error");

        ExprToken* operand1 = *(exprVector.end() - 3);
        if (operand1->type() != ExprToken::Type::NonTerminal) {
            deallocateVector();
            throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
        }

        ExprToken* result = performOperation(operation, operand1, operand2);
        if (result == nullptr) {
            deallocateVector();
            throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
        }

        operation = nullptr;
        operand1 = nullptr;
        operand2 = nullptr;
        vectorPopN(3);

        exprVector.push_back(result);

        break;
    }
    case Token::Type::RightBrace: {
        uint32_t stackSize = exprVector.size();
        if (stackSize < 3) {
            deallocateVector();
            throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
        }

        auto nextTermIt = exprVector.end();
        nextTermIt--;
        if ((*nextTermIt) == topTerm) { // at top must be )
            nextTermIt--;

            if ((*nextTermIt)->check(ExprToken::Type::Terminal, Token::Type::LeftBrace)) { // Empty braces or parameter-less functions are not allowed
                deallocateVector();
                throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
            }
            else if ((*nextTermIt)->type() == ExprToken::Type::NonTerminal) { // we have E) and are not sure what it is
                nextTermIt--;

                if ((*nextTermIt)->check(ExprToken::Type::Terminal, Token::Type::Comma)) { // we have ,E) and it's function
                    uint32_t stackPos = stackSize - 2;

                    if (stackPos < 4) { // not enough space for best case func(E,E)
                        deallocateVector();
                        throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
                    }

                    uint32_t paramCount = 0;
                    reduceMultiparamFunc(stackPos, &paramCount);
                }
                else if ((*nextTermIt)->check(ExprToken::Type::Terminal, Token::Type::LeftBrace)) { // it's (E) and we don't know if it is single param func or just (E)
                    if (stackSize >= 4) {
                        auto leftBraceIt = nextTermIt;
                        nextTermIt--;

                        if ((*nextTermIt)->check(ExprToken::Type::Terminal, Token::Type::Function)) { // we have id(E) and it's function
                            // Collect params
                            std::vector<ExprToken *> params;
                            params.push_back(*(nextTermIt + 2));

                            ExprToken *result = performFunction((*nextTermIt), params);
                            if (result == nullptr)
                            {
                                deallocateVector();
                                throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
                            }
                            else
                            {
                                vectorPopN(4); // funcId + '(' + param + ')'
                                exprVector.push_back(result);
                            }
                        }
                        else { // it's just (E)
                            ExprToken *red = (*leftBraceIt);
                            red->setType(ExprToken::Type::NonTerminal);
                            red->setVal((*(exprVector.end() - 2))->val());
                            vectorPopN(2);
                        }
                    }
                    else { // it can only be (E) if we have just 3 items on the stack
                        ExprToken *red = (*nextTermIt);
                        red->setType(ExprToken::Type::NonTerminal);
                        red->setVal((*(exprVector.end() - 2))->val());
                        vectorPopN(2);
                    }
                }
                else {
                    deallocateVector();
                    throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
                }
            }
            else {
                deallocateVector();
                throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
            }
        }
        else {
            deallocateVector();
            throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
        }
        break;
    }
    default:
        deallocateVector();
        throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
    }
}

void Parser::reduceMultiparamFunc(uint32_t stackPos, uint32_t *paramCount)
{
    if (stackPos == 0)
    {
        deallocateVector();
        throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
    }

    ExprToken* first = exprVector[stackPos];
    ExprToken* second = exprVector[stackPos - 1];
    if (first->type() == ExprToken::Type::NonTerminal) { // got E,E..) expect , or (
        (*paramCount)++;

        if (second->check(ExprToken::Type::Terminal, Token::Type::Comma)) { // we got ,E,E..), enter recursion
            reduceMultiparamFunc(stackPos - 2, paramCount);
        }
        else if (second->check(ExprToken::Type::Terminal,Token::Type::LeftBrace)) { // got (E,..,E), expect id
            if (stackPos < 2) {
                deallocateVector();
                throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
            }

            // check for function id token before (
            ExprToken* function = exprVector[stackPos - 2];
            if (!function->check(ExprToken::Type::Terminal, Token::Type::Function)) {
                deallocateVector();
                throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
            }

            // Collect params
            std::vector<ExprToken *> params;
            for (uint32_t i = 0; i < *paramCount; i++)
            {
                // Skip the ,
                params.push_back(exprVector[stackPos + i * 2]);
            }

            ExprToken* result = performFunction(function, params);
            if (result == nullptr)
            {
                deallocateVector();
                throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
            }
            else
            {
                vectorPopN((*paramCount) * 2 + 3); // funcId + '(' + paramCount * 2 + ')'
                exprVector.push_back(result);
            }
        }
        else {
            deallocateVector();
            throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
        }
    }
    else {
        deallocateVector();
        throw SyntaxException(); //throw new std::runtime_error("Syntax Error");
    }
}

Parser::ExprToken *Parser::findTopmostTerminal()
{
    auto it = exprVector.end();

    while (it != exprVector.begin())
    {
        it--;
        if ((*it)->type() == ExprToken::Type::Terminal)
            return *it;
    }

    return nullptr;
}

void Parser::deallocateVector()
{
    while (exprVector.size() > 0)
    {
        delete exprVector.back();
        exprVector.pop_back();
    }
}

void Parser::vectorPopN(uint32_t n)
{
    for (uint32_t i = 0; i < n; i++)
    {
        delete exprVector.back();
        exprVector.pop_back();
    }
}

Parser::ExprToken::ExprToken()
{

}

Parser::ExprToken::ExprToken(Parser::ExprToken::Type type, const Token *token) :
    _type(type),
    _token(token)
{

}

Parser::ExprToken::Type Parser::ExprToken::type() const
{
    return _type;
}

void Parser::ExprToken::setType(Parser::ExprToken::Type type)
{
    _type = type;
}

const Token *Parser::ExprToken::token() const
{
    return _token;
}

void Parser::ExprToken::setToken(const Token *token)
{
    _token = token;
}

bool Parser::ExprToken::check(Parser::ExprToken::Type type, Token::Type tokenType)
{
    return _type == type && _token->type() == tokenType;
}

double Parser::ExprToken::val() const
{
    return _val;
}

void Parser::ExprToken::setVal(double val)
{
    _val = val;
}


