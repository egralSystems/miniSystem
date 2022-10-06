#pragma once

#include <wren.hpp>

#include "stream.hpp"
#include "fs.hpp"

void writeFn(WrenVM *vm, const char *msg);
void errorFn(WrenVM *vm, WrenErrorType errorType, const char *module, const int line, const char *msg);

struct IOIfs
{
    bool console = false;
    Stream<std::string> consoleStream;

    bool fs = false;
    FS fileSystem;
};

class IO
{
private:
    IOIfs *ioIfs;

public:
    IO()
    {
        ioIfs = new IOIfs;
    };
    ~IO()
    {
        delete ioIfs;
    };

    void registerIO(WrenVM *vm);

    void registerIf(StreamIf<std::string> *consoleIf);
    void registerIf(FSIf *fsIf);
};
