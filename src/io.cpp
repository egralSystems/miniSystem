#include "io.hpp"
#include "stream.hpp"

void IO::registerIO(WrenVM *vm)
{
    wrenSetUserData(vm, &ioIfs);
}

void IO::registerIf(StreamIf<std::string> *consoleIf)
{
    ioIfs.consoleStream.init(consoleIf);
    ioIfs.console = true;
}

void IO::registerIf(FSIf *fsIf)
{
    ioIfs.fileSystem.init(fsIf);
    ioIfs.fs = true;
}

void writeFn(WrenVM *vm, const char *msg)
{
    IOIfs *ioIfs = (IOIfs *)wrenGetUserData(vm);
    ioIfs->consoleStream << msg;
}

void errorFn(WrenVM *vm, WrenErrorType errorType, const char *module, const int line, const char *msg)
{
    switch (errorType)
    {
    case WREN_ERROR_COMPILE:
    {
        IOIfs *ioIfs = (IOIfs *)wrenGetUserData(vm);
        ioIfs->consoleStream << "[" << std::to_string(line) << "] [Error] " << msg << "\n";
    }
    break;
    case WREN_ERROR_STACK_TRACE:
    {
        IOIfs *ioIfs = (IOIfs *)wrenGetUserData(vm);
        ioIfs->consoleStream << "[" << module << " line " << std::to_string(line) << "] in " << msg << "\n";
    }
    break;
    case WREN_ERROR_RUNTIME:
    {
        IOIfs *ioIfs = (IOIfs *)wrenGetUserData(vm);
        ioIfs->consoleStream << "[Runtime Error] " << msg << "\n";
    }
    break;
    }
}