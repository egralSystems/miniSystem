#include <string>
#include <vector>
#include <cstring>

#include <wren.hpp>

#include "stream.hpp"
#include "fs.hpp"
#include "miniSystem.hpp"

Stream<std::string> consoleStream;
File fileSystem;

void writeFn(WrenVM *vm, const char *msg)
{
    consoleStream << msg;
}

void errorFn(WrenVM *vm, WrenErrorType errorType, const char *module, const int line, const char *msg)
{
    switch (errorType)
    {
    case WREN_ERROR_COMPILE:
    {
        consoleStream << "[" << std::to_string(line) << "] [Error] " << msg << "\n";
    }
    break;
    case WREN_ERROR_STACK_TRACE:
    {
        consoleStream << "[" << module << " line " << std::to_string(line) << "] in " << msg << "\n";
    }
    break;
    case WREN_ERROR_RUNTIME:
    {
        consoleStream << "[Runtime Error] " << msg << "\n";
    }
    break;
    }
}

WrenForeignClassMethods bindForeignClass(WrenVM *vm, const char *module, const char *className)
{
    WrenForeignClassMethods methods;

    methods.allocate = nullptr;
    methods.finalize = nullptr;

    if (strcmp(className, "File") == 0)
    {
        methods.allocate = fileAllocate;
        methods.finalize = fileFinalize;
    }

    return methods;
}

WrenForeignMethodFn bindForeignMethod(WrenVM *vm, const char *module, const char *className, bool isStatic, const char *sig)
{
    if (!strcmp(module, "main"))
    {
        if (!strcmp(className, "File"))
        {
            if (!isStatic && !strcmp(sig, "read(_)"))
                return fileRead;
            if (!isStatic && !strcmp(sig, "write(_)"))
                return fileWrite;
            if (!isStatic && !strcmp(sig, "size()"))
                return fileSize;
            if (!isStatic && !strcmp(sig, "seek(_)"))
                return fileSeek;
            if (!isStatic && !strcmp(sig, "close()"))
                return fileClose;
        }
    }

    return nullptr;
}

// template <typename Cif, typename Fif>
// MiniSystem<Cif, Fif>::MiniSystem()
// {
//     WrenConfiguration config;
//     wrenInitConfiguration(&config);

//     config.writeFn = writeFn;
//     config.errorFn = errorFn;
//     config.bindForeignClassFn = bindForeignClass;
//     config.bindForeignMethodFn = bindForeignMethod;

//     vm = wrenNewVM(&config);

//     consoleStream.init(new Cif);
// }

// template <typename Cif, typename Fif>
// MiniSystem<Cif, Fif>::~MiniSystem() {}

// template <typename Cif, typename Fif>
// int MiniSystem<Cif, Fif>::eval(std::string prog)
// {
//     wrenInterpret(vm, "main", prog.c_str());
//     return 0;
// }
