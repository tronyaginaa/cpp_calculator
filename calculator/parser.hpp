#ifndef parser_hpp
#define parser_hpp

#include "basic_operations.hpp"
#include <iostream>
#include <queue>
#include <vector>
#include <stack>


enum ElementType{
    NUM,
    BASIC_OP,
    LOADABLE_OP
};

class ExpressionElement{
public:
    ExpressionElement() = default;
    ElementType type;
};

class NumberElement : public ExpressionElement{
public:
    double value;
    NumberElement(double _value) : value(_value) {type = NUM;};
};

class BasicOperation : public ExpressionElement{
public:
    char operationName;
    BasicOperation(char name): operationName(name) {type = BASIC_OP;};
};

class LoadableOperation : public ExpressionElement{
public:
    std::string operationName = "";
    LoadableOperation(std::string name): operationName(name) {type = LOADABLE_OP;};
};

class ElementsContainer{
public:
    ElementsContainer() = default;
    std::queue<ExpressionElement*> elementsQueue;
    void printQueue();
    void parseExpression(std::string& expressionString);
private:
    void makeUnaryMinys(std::string& expressionString);
};

class PostfixParser{
public:
    PostfixParser() = default;
    std::queue<ExpressionElement*> outputQueue;
    void printQueue();
    void parseToRPN(std::queue<ExpressionElement*>& elementQueue);
private:
    std::stack<ExpressionElement*> opStack;
};

#endif /* parser_hpp */
