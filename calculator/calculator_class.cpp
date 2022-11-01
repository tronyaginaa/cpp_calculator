#include "calculator_class.hpp"

double Calculator::calculation(std::string &expression){
    elem.parseExpression(expression);
    rpn.parseToRPN(elem.elementsQueue);
    return calc.solve(rpn.outputQueue);
}
