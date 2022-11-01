#include "plugins_usage.hpp"

void PluginLoader::LoadFunction(std::string const& functionName) {
    std::string path = pluginsPath + "lib" + functionName + ".so";
    void* lib = dlopen(path.c_str(), RTLD_LAZY);
    if (lib == NULL) {
        throw std::runtime_error("Lib wasn't load ");
    }
    double (*func)(double) = (double(*)(double))dlsym(lib, "fun");
    if (func == NULL) {
        throw std::runtime_error("Not such function");
        return;
    }
    functionMap.emplace(functionName, func);
    return;
}

bool PluginLoader::constainsFunction(const std::string &func_name){
    return functionMap.find(func_name) != functionMap.end();
}

double PluginLoader::getFunctionResult(std::string &functionName, double a){
    return functionMap[functionName](a);
}
