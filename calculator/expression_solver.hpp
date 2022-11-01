#ifndef expression_solver_hpp
#define expression_solver_hpp

#include "parser.hpp"
#include "plugins_usage.hpp"

class Solver{
public:
    Solver() = default;
    double solve(std::queue<ExpressionElement*>& rpnQueue);
    ~Solver() {while(!countStack.empty()) countStack.pop();}
private:
    std::stack<ExpressionElement*> countStack;
};

#endif /* expression_solver_hpp */
