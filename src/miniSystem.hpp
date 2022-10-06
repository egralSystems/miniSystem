#pragma once
#include <wren.hpp>

#include "stream.hpp"
#include "fs.hpp"

extern Stream<std::string> consoleStream;
extern File fileSystem;

void writeFn(WrenVM *vm, const char *msg);
void errorFn(WrenVM *vm, WrenErrorType errorType, const char *module, const int line, const char *msg);
WrenForeignClassMethods bindForeignClass(WrenVM *vm, const char *module, const char *className);
WrenForeignMethodFn bindForeignMethod(WrenVM *vm, const char *module, const char *className, bool isStatic, const char *sig);

template <typename Cif, typename Fif>
class MiniSystem
{
private:
    WrenVM *vm;

    bool console = false;
    bool fs = false;

public:
    MiniSystem()
    {
        WrenConfiguration config;
        wrenInitConfiguration(&config);

        config.writeFn = writeFn;
        config.errorFn = errorFn;
        config.bindForeignClassFn = bindForeignClass;
        config.bindForeignMethodFn = bindForeignMethod;

        vm = wrenNewVM(&config);

        consoleStream.init(new Cif);
    }
    ~MiniSystem() {}

    int eval(std::string prog)
    {
        wrenInterpret(vm, "main", prog.c_str());
        return 0;
    }
};