#include <memory>
#include <string>

#include "lexer.cpp"
#include "parser.cpp"

static int CurTok;
static int getNextToken() {
    return CurTok = gettok();
}

std::unique_ptr<ExprAST> LogError(const char *Str){
    fprintf(stderr, "Error: %s\n", Str);
    return nullptr;
}

std::unique_ptr<PrototypeAST> LoggErrorP(const char *Str){
    LogError(Str);
    return nullptr;
}

static std::unique_ptr<ExprAST> ParseNumberExpr() {
    auto Result = std::make_unique<NumberExprAST>(NumVal);
    getNextToken();
    return std::move(Result);
}

static std::unique_ptr<ExprAST> ParseParentExpr() {
    getNextToken();
    auto V = ParseExpression();
    if (!V)
        return nullptr;

    if (CurTok != ')')
        return LogError("expected )");
    getNextToken();
    return V;
}