#pragma once
#include <wren.hpp>

#include "stream.hpp"
#include "fs.hpp"
#include "io.hpp"

WrenForeignClassMethods bindForeignClass(WrenVM *vm, const char *module, const char *className);
WrenForeignMethodFn bindForeignMethod(WrenVM *vm, const char *module, const char *className, bool isStatic, const char *sig);

class MiniSystem
{
private:
    IO io;
    WrenVM *vm;

public:
    MiniSystem(IO new_io)
    {
        WrenConfiguration config;
        wrenInitConfiguration(&config);

        // TODO: add module loader
        config.writeFn = writeFn;
        config.errorFn = errorFn;
        config.bindForeignClassFn = bindForeignClass;
        config.bindForeignMethodFn = bindForeignMethod;

        vm = wrenNewVM(&config);

        io = new_io;

        io.registerIO(vm);
    }
    ~MiniSystem() {}

    int eval(std::string prog)
    {
        wrenInterpret(vm, "main", prog.c_str());
        return 0;
    }
};