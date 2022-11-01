#include <iostream>
#include <map>
#include <functional>
#include <string>

using  op = std::function<double(double,double)>;

class Operations{
public:
    Operations();
    std::map<char const, int> priorityMap;
    std::map<char const, op> operationsMap;
    int getPriority(char const& operationName);
    double getOperationResult(char const& operationName, double a, double b);
    bool containsOperation(char const& operationName);
    ~Operations() {operationsMap.clear(); priorityMap.clear();}
private:
};

