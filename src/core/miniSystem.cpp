#include <stdio.h>
#include <string>
#include <stream.hpp>

#include "miniSystem.hpp"

MiniSystem::MiniSystem(StreamIf<std::string> *consoleStreamIf)
{
    consoleStream.init(consoleStreamIf);

    WrenConfiguration config;
    wrenInitConfiguration(&config);
    config.writeFn = MiniSystem::writeFn;
    config.errorFn = MiniSystem::errorFn;
    vm = wrenNewVM(&config);
}

MiniSystem::~MiniSystem()
{
    wrenFreeVM(vm);
}

void MiniSystem::writeFn(WrenVM *vm, const char *msg)
{
    consoleStream << msg;
}
void MiniSystem::errorFn(WrenVM *vm, WrenErrorType errorType, const char *module, const int line, const char *msg)
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

int MiniSystem::eval(const char *prog)
{
    return wrenInterpret(vm, "main", prog);
}