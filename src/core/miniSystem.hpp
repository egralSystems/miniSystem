#pragma once
#include <wren.hpp>
#include <stream.hpp>

extern Stream<std::string> consoleStream;

class MiniSystem
{
private:
    WrenVM *vm;

public:
    MiniSystem(StreamIf<std::string> *consoleStreamIf);
    ~MiniSystem();

    static void writeFn(WrenVM *vm, const char *msg)
    {
        consoleStream << msg;
    }

    static void errorFn(WrenVM *vm, WrenErrorType errorType, const char *module, const int line, const char *msg)
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

    int
    eval(const char *);
};