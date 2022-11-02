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
    int getPriority(const char operationName);
    double getOperationResult(const char operationName, double a, double b);
    bool containsOperation(const char operationName);
    ~Operations() {operationsMap.clear(); priorityMap.clear();}
private:
};

