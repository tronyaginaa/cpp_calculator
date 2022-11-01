#include "parser.hpp"
#include <exception>

void ElementsContainer::makeUnaryMinys(std::string& expressionString){
    for (int i = 0; i < expressionString.length(); i++) {
        char ch = expressionString[i];
        if (ch == '-' && (i == 0 || expressionString[i - 1] == '('))
            expressionString[i] = '~';
    }
}

void ElementsContainer::parseExpression(std::string& expressionString){
    Operations* operation;
    try {
        operation = new Operations;
    } catch (std::bad_alloc) {
        throw std::runtime_error("Memory allocation error");
    }
    makeUnaryMinys(expressionString);
    int pos = 0;
    while (pos < expressionString.length()) {
        std::string operationName;
        while(isalpha(expressionString[pos])){
            operationName += expressionString[pos];
            pos++;
        }
        if (!operationName.empty()){
            LoadableOperation* loadOp;
            try {
            loadOp = new LoadableOperation(operationName);
            } catch (std::bad_alloc) {
                throw std::runtime_error("Memory allocation error");
            }
            elementsQueue.push(loadOp);
        }
        std::string number;
        while (isdigit(expressionString[pos])) {
            if(expressionString[pos + 1] == '.'){
                number += expressionString[pos];
                pos++;
            }
            number += expressionString[pos];
            pos++;
        }
        if (!number.empty()) {
            NumberElement* num;
            try {
                num = new NumberElement(std::stod(number));
            } catch (std::bad_alloc) {
                throw std::runtime_error("Memory allocation error");
            }
            elementsQueue.push(num);
        }
        char ch = expressionString[pos];
        if (operation->containsOperation(ch) || ch == '(' || ch == ')') {
            BasicOperation* basOp;
            try {
                basOp = new BasicOperation(ch);
            } catch (std::bad_alloc) {
                throw std::runtime_error("Memory allocation error");
            }
            elementsQueue.push(basOp);
            pos++;
        }
    }
    delete operation;
}

void ElementsContainer::printQueue(){
    std::queue<ExpressionElement*> tmp;
    std::cout<<"elements queue:\n";
    while (!elementsQueue.empty()) {
        ExpressionElement* element = elementsQueue.front();
        tmp.push(element);
        elementsQueue.pop();
        switch (element->type) {
            case NUM:
                std::cout<<((NumberElement*)element)->value<<std::endl;
                break;
            case BASIC_OP:
                std::cout<<((BasicOperation*)element)->operationName<<std::endl;
                break;
            case LOADABLE_OP:
                std::cout<<((LoadableOperation*)element)->operationName<<std::endl;
                break;
            default:
                break;
        }
    }
    while (!tmp.empty()) {
        ExpressionElement* element = tmp.front();
        elementsQueue.push(element);
        tmp.pop();
    }
}

void PostfixParser::parseToRPN(std::queue<ExpressionElement *>& elementQueue){
    Operations* operation;
    try {
        operation = new Operations;
    } catch (std::bad_alloc) {
        throw std::runtime_error("Memory allocation error");
    }
    ExpressionElement* element;
    while (!elementQueue.empty()) {
        element = elementQueue.front();
        elementQueue.pop();
        if (element->type == BASIC_OP) {
            if (((BasicOperation*)element)->operationName == '(')
                opStack.push(element);
            else if (((BasicOperation*)element)->operationName == ')'){
                while (!opStack.empty() && ((BasicOperation*)opStack.top())->operationName != '(' ) {
                    outputQueue.push(opStack.top());
                    opStack.pop();
                }
                opStack.pop();
            }
            else {
                while (!(opStack.empty() || operation->getPriority(((BasicOperation*)opStack.top())->operationName) < operation->getPriority(((BasicOperation*)element)->operationName))) {
                    outputQueue.push(opStack.top());
                    opStack.pop();
                }
                opStack.push(element);
            }
        }
        if (element->type == LOADABLE_OP) {
            while (!opStack.empty() && operation->getPriority(((BasicOperation*)opStack.top())->operationName)  > 4) {
                outputQueue.push(opStack.top());
                opStack.pop();
            }
            opStack.push(element);
        }
        if (element->type == NUM)
            outputQueue.push(element);
    }
    while (!opStack.empty()) {
        outputQueue.push(opStack.top());
        opStack.pop();
    }
    delete operation;
}

void PostfixParser::printQueue(){
    std::queue<ExpressionElement*> tmp;
    std::cout<<"rpn queue:\n";
    while (!outputQueue.empty()) {
        ExpressionElement* element = outputQueue.front();
        tmp.push(element);
        outputQueue.pop();
        switch (element->type) {
            case NUM:
                std::cout<<((NumberElement*)element)->value<<std::endl;
                break;
            case BASIC_OP:
                std::cout<<((BasicOperation*)element)->operationName<<std::endl;
                break;
            case LOADABLE_OP:
                std::cout<<((LoadableOperation*)element)->operationName<<std::endl;
                break;
            default:
                break;
        }
    }
    while (!tmp.empty()) {
        ExpressionElement* element = tmp.front();
        outputQueue.push(element);
        tmp.pop();
    }
}
