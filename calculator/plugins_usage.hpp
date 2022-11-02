#ifndef plugins_usage_hpp
#define plugins_usage_hpp


#include <iostream>
#include <map>
#include <functional>
#include <string>
#include <dlfcn.h>
//#include "dlfc_forWindows.hpp"

using  func = std::function<double(double)>;

class PluginLoader{
public:
    double getFunctionResult(std::string& functionName, double a);
    std::map<std::string, func> functionMap;
    std::string const pluginsPath = "../myLibs/";
    void LoadFunction(std::string const& functionName);
    bool constainsFunction(std::string const& functionName);
};

#endif /* plugins_usage_hpp */
