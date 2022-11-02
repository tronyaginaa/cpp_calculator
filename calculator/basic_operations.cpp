#include "basic_operations.hpp"

Operations::Operations(){
    operationsMap.emplace('+',[](double a, double b)->double{ return a + b; });
    operationsMap.emplace('-',[](double a, double b)->double{ return a - b; });
    operationsMap.emplace('*',[](double a, double b)->double{ return a * b; });
    operationsMap.emplace('/',[](double a, double b)->double{ return a / b; });
    operationsMap.emplace('~',[](double a, double b)->double{ return -a ; });
    priorityMap['+'] = 1;
    priorityMap['-'] = 1;
    priorityMap['*'] = 2;
    priorityMap['/'] = 2;
    priorityMap['~'] = 4;
    priorityMap['('] = 0;
    priorityMap[')'] = 0;
};

int Operations::getPriority(const char operationName){
    return priorityMap[operationName];
}

double Operations::getOperationResult(const char operationName, double a, double b){
    return operationsMap[operationName](a,b);
}

bool Operations::containsOperation(const char operationName){
    return operationsMap.find(operationName) != operationsMap.end();
}
