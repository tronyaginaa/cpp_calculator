#include "expression_solver.hpp"


double Solver::solve(std::queue<ExpressionElement *>& rpnQueue){
    ExpressionElement* element;
    Operations* operation;
    try {
        operation = new Operations;
    } catch(std::bad_alloc){
        throw std::runtime_error("Memory allocation error");
    }
    PluginLoader* plugins;
    try {
        plugins = new PluginLoader;
    } catch(std::bad_alloc){
        throw std::runtime_error("Memory allocation error");
    }
    while (!rpnQueue.empty()) {
        ExpressionElement* first, *second;
        element = rpnQueue.front();
        rpnQueue.pop();
        if(element->type == NUM)
            countStack.push(element);
        if(element->type == BASIC_OP){
            first = countStack.top();
            countStack.pop();
            if (((BasicOperation*)element)->operationName != '~') {
                second = countStack.top();
                countStack.pop();
                ((NumberElement*)first)->value = operation->getOperationResult(((BasicOperation*)element)->operationName, ((NumberElement*)second)->value, ((NumberElement*)first)->value);
            }
            else
                ((NumberElement*)first)->value = operation->getOperationResult(((BasicOperation*)element)->operationName,((NumberElement*)first)->value, 0);
            countStack.push(first);
        }
        if (element->type == LOADABLE_OP) {
            if (!plugins->constainsFunction(((LoadableOperation*)element)->operationName))
                plugins->LoadFunction(((LoadableOperation*)element)->operationName);
            first = countStack.top();
            countStack.pop();
            ((NumberElement*)first)->value = plugins->getFunctionResult(((LoadableOperation*)element)->operationName, ((NumberElement*)first)->value);
            countStack.push(first);
        }
    }
    delete operation;
    delete plugins;
    return ((NumberElement*)countStack.top())->value;
}
