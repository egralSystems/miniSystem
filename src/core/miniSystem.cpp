#include <stdio.h>
#include <string>
#include <stream.hpp>

#include "miniSystem.hpp"

Stream<std::string> consoleStream;

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

int MiniSystem::eval(const char *prog)
{
    return wrenInterpret(vm, "main", prog);
}