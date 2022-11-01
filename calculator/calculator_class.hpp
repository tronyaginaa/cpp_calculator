#ifndef calculator_class_hpp
#define calculator_class_hpp

#include "expression_solver.hpp"

class Calculator{
public:
    Calculator() = default;
    double calculation(std::string& expression);
private:
    ElementsContainer elem;
    PostfixParser rpn;
    Solver calc;
};

#endif /* calculator_class_hpp */
