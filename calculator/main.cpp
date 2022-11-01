#include "calculator_class.hpp"

int main(){
    while (1) {
        std::string expression;
        std::cout<<"> ";
        std::getline(std::cin, expression);
        if (expression == "")
            break;
        Calculator myCalculator;
        std::cout << "result: " << myCalculator.calculation(expression) << std::endl;
    }
    return 0;
}
