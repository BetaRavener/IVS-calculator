#include "inc/core/scanner.h"


Scanner::Scanner()
{

}


Scanner::~Scanner()
{

}


TokenVector Scanner::scan(std::string input)
{
    // Dynamic allocation is required because of Token inheritance
    TokenVector tokenVector;

    std::string tmpStr = "";

    // Current character
    char symbol;

    // Last character
    char lastChar = 0;
    bool isLastChar = false;

    // Index of array
    int i = 0;

    State state = ST_Empty;

    while(true){
        if (state == ST_Exit)
            break;

        if (isLastChar){
            symbol = lastChar;
            isLastChar = false;
        }
        else {
            symbol = input[i];
            i++;
        }

        switch (state) {
            case ST_Exit:
                continue;
            case ST_Empty: {
                if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z')){
                    tmpStr = symbol;
                    state = ST_Function;
                }
                else if (symbol >= '0' && symbol <= '9') {
                    tmpStr = symbol;
                    state = ST_Number;
                }
                else if (isspace(symbol)) {
                    continue;
                }
                else if (symbol == '\0') {
                    state = ST_Exit;
                }
                else {
                    switch(symbol){
                        case '(':
                            tokenVector.add(new Token(Token::Type::LeftBrace));
                        break;
                        case ')':
                            tokenVector.add(new Token(Token::Type::RightBrace));
                        break;
                        case '+':
                            tokenVector.add(new Token(Token::Type::Plus));
                        break;
                        case '-':
                            tokenVector.add(new Token(Token::Type::Minus));
                        break;
                        case '*':
                            tokenVector.add(new Token(Token::Type::Multiply));
                        break;
                        case '/':
                            tokenVector.add(new Token(Token::Type::Divide));
                        break;
                        case '^':
                            tokenVector.add(new FunctionToken(FunctionToken::FunctionId::Exponential));
                        break;
                        default:
                            // Error handling - unexpected char
                            throw std::runtime_error("unexpected character in expression");
                        break;
                    }
                }
                break;
            }
            case ST_Number: {
                if (symbol >= '0' && symbol <= '9'){
                    tmpStr += symbol;
                    state = ST_Number;
                }else if (symbol == ',') {
                    tmpStr += '.';
                    state = ST_Double;
                }else{
                    try{
                        tokenVector.add(new NumberToken(std::stod(tmpStr)));
                    }catch(std::invalid_argument){
                        // Error handling - unexpected number format
                        throw std::runtime_error("unexpected number format");
                    }

                    // Save last character
                    lastChar = symbol;
                    isLastChar = true;

                    // Change state
                    state = ST_Empty;
                }
                break;
            }
            case ST_Double: {
                if (symbol >= '0' && symbol <= '9'){
                    tmpStr += symbol;
                    state = ST_DoubleDec;
                }else{
                    throw std::runtime_error("unexpected number format");
                }
                break;
            }
            case ST_DoubleDec: {
                if (symbol >= '0' && symbol <= '9'){
                    tmpStr += symbol;
                    state = ST_DoubleDec;
                }else{
                    try{
                        tokenVector.add(new NumberToken(std::stod(tmpStr)));
                    }catch(std::invalid_argument){
                        // Error handling - unexpected number format
                        throw std::runtime_error("unexpected number format");
                    }

                    // Save last character
                    lastChar = symbol;
                    isLastChar = true;

                    // Change state
                    state = ST_Empty;
                }
                break;
            }
            case ST_Function: {
                if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z')){
                    tmpStr += symbol;
                    state = ST_Function;
                }else{
                    tokenVector.add(new FunctionToken(FunctionToken::FunctionId::Exponential));

                    if (tmpStr.compare("fac") == 0){
                        tokenVector.add(new FunctionToken(FunctionToken::FunctionId::Factorial));
                    }else if (tmpStr.compare("sqrt") == 0){
                        tokenVector.add(new FunctionToken(FunctionToken::FunctionId::SquareRoot));
                    }else{
                        // Error handling - unexpected function
                        throw std::runtime_error("unexpected function in expression");
                    }

                    // Save last character
                    lastChar = symbol;
                    isLastChar = true;

                    // Change state
                    state = ST_Empty;
                }
                break;
            }
        }
    }

    return tokenVector;
}
