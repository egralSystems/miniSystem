#include "module.hpp"
#include "stream.hpp"

// Module

Module::Module(ModuleIf *mif)
{
    this->mif = mif;
}

Module::~Module()
{
    delete mif;
}

bool Module::bindClass(WrenForeignClassMethods *methods, std::string module, std::string name)
{
    return mif->bindClass(methods, module, name);
}

WrenForeignMethodFn Module::bindMethods(std::string name, bool isStatic, std::string sig)
{
    return mif->bindMethods(name, isStatic, sig);
}

WrenLoadModuleResult Module::loadModule(WrenVM *vm)
{
    return mif->loadModule(vm);
}

// Module manager

void ModuleManager::registerIO(WrenVM *vm)
{
    wrenSetUserData(vm, (void *)modules);
}

void ModuleManager::registerIf(StreamIf<std::string> *consoleIf)
{
    modules->consoleStream.init(consoleIf);
}

void ModuleManager::registerIf(FSIf *fsIf)
{
    modules->fileSystem.init(fsIf);
}

void ModuleManager::addModule(std::string name, Module *module)
{
    modules->modules[name] = module;
}

// Basic IO functions

void writeFn(WrenVM *vm, const char *msg)
{
    Modules *modules = (Modules *)wrenGetUserData(vm);
    modules->consoleStream << msg;
}

void errorFn(WrenVM *vm, WrenErrorType errorType, const char *module, const int line, const char *msg)
{
    switch (errorType)
    {
    case WREN_ERROR_COMPILE:
    {
        Modules *modules = (Modules *)wrenGetUserData(vm);
        modules->consoleStream << "[" << std::to_string(line) << "] [Error] " << msg << "\n";
    }
    break;
    case WREN_ERROR_STACK_TRACE:
    {
        Modules *modules = (Modules *)wrenGetUserData(vm);
        modules->consoleStream << "[" << module << " line " << std::to_string(line) << "] in " << msg << "\n";
    }
    break;
    case WREN_ERROR_RUNTIME:
    {
        Modules *modules = (Modules *)wrenGetUserData(vm);
        modules->consoleStream << "[Runtime Error] " << msg << "\n";
    }
    break;
    }
}

WrenLoadModuleResult loadModule(WrenVM *vm, const char *name)
{
    WrenLoadModuleResult res;

    if (name == "FS")
    {
        res.source = "foreign class File {\n"
                     "  construct open(path, options) {}\n"
                     "  foreign close()\n"
                     "  foreign read(count)\n"
                     "}";
    }

    Modules *modules = (Modules *)wrenGetUserData(vm);
    if (modules->modules.find(name) != modules->modules.end())
        res = modules->modules[name]->loadModule(vm);

    return res;
}