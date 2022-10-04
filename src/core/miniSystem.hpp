#pragma once
#include <wren.hpp>
#include <stream.hpp>

class MiniSystem
{
private:
    WrenVM *vm;
    static Stream<std::string> consoleStream;

public:
    MiniSystem(StreamIf<std::string> *consoleStreamIf);
    ~MiniSystem();

    static void writeFn(WrenVM *, const char *);
    static void errorFn(WrenVM *, WrenErrorType, const char *, const int, const char *);

    int
    eval(const char *);
};