#pragma once

#include <unordered_map>

#include <wren.hpp>

#include "stream.hpp"
#include "fs.hpp"

void writeFn(WrenVM *vm, const char *msg);
void errorFn(WrenVM *vm, WrenErrorType errorType, const char *module, const int line, const char *msg);
WrenLoadModuleResult loadModule(WrenVM *vm, const char *name);

// WrenLoadModuleCompleteFn

class ModuleIf
{
public:
    ModuleIf(){};
    ~ModuleIf(){};

    virtual bool bindClass(WrenForeignClassMethods *methods, std::string module, std::string name) = 0;
    virtual WrenForeignMethodFn bindMethods(std::string name, bool isStatic, std::string sig) = 0;
    virtual WrenLoadModuleResult loadModule(WrenVM *vm) = 0;
};

class Module
{
private:
    ModuleIf *mif;

public:
    Module(ModuleIf *mif);
    ~Module();

    bool bindClass(WrenForeignClassMethods *methods, std::string module, std::string name);
    WrenForeignMethodFn bindMethods(std::string name, bool isStatic, std::string sig);
    WrenLoadModuleResult loadModule(WrenVM *vm);
};

struct Modules
{
    Stream<std::string> consoleStream;
    FS fileSystem;

    // The remaining not critical modules
    std::unordered_map<std::string, Module *> modules;
};

class ModuleManager
{
private:
    Modules *modules;

public:
    ModuleManager()
    {
        modules = new Modules;
    };
    ~ModuleManager()
    {
        delete modules;
    };

    void registerIO(WrenVM *vm);

    void registerIf(StreamIf<std::string> *consoleIf);
    void registerIf(FSIf *fsIf);

    void addModule(std::string name, Module *module);
};
