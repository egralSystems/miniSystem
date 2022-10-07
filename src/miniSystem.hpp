#pragma once
#include <wren.hpp>

#include "stream.hpp"
#include "fs.hpp"
#include "module.hpp"

WrenForeignClassMethods bindForeignClass(WrenVM *vm, const char *module, const char *className);
WrenForeignMethodFn bindForeignMethod(WrenVM *vm, const char *module, const char *className, bool isStatic, const char *sig);

class MiniSystem
{
private:
    ModuleManager *io;
    WrenVM *vm;

public:
    MiniSystem(ModuleManager *new_moduleMan)
    {
        WrenConfiguration config;
        wrenInitConfiguration(&config);

        // TODO: add module loader
        config.writeFn = writeFn;
        config.errorFn = errorFn;
        config.bindForeignClassFn = bindForeignClass;
        config.bindForeignMethodFn = bindForeignMethod;
        config.loadModuleFn = loadModule;

        vm = wrenNewVM(&config);

        io = new_moduleMan;

        io->registerIO(vm);
    }
    ~MiniSystem()
    {
        delete io;
        wrenFreeVM(vm);
    }

    int eval(std::string prog)
    {
        wrenInterpret(vm, "main", prog.c_str());
        return 0;
    }
};