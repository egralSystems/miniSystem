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

    if (strcmp(className, "File") == 0)
    {
        // methods.allocate
    }

    return methods;
}

WrenForeignMethodFn bindForeignMethod(WrenVM *vm, const char *module, const char *className, bool isStatic, const char *sig)
{
    return nullptr;
}

MiniSystem::MiniSystem(StreamIf<std::string> *cif, FileIf *fif)
{
    WrenConfiguration config;
    wrenInitConfiguration(&config);

    config.writeFn = &writeFn;
    config.errorFn = &errorFn;
    config.bindForeignClassFn = &bindForeignClass;
    config.bindForeignMethodFn = &bindForeignMethod;

    vm = wrenNewVM(&config);

    if (cif)
    {
        console = true;
        consoleStream.init(cif);
    }

    if (fif)
    {
        fs = true;
        fileSystem.init(fif);
    }
}

MiniSystem::~MiniSystem() {}

int MiniSystem::eval(std::string prog)
{
    wrenInterpret(vm, "main", prog.c_str());
    return 0;
}
