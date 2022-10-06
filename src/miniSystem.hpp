#pragma once
#include "stream.hpp"
#include "fs.hpp"

extern Stream<std::string> consoleStream;
extern File fileSystem;

class MiniSystem
{
private:
    WrenVM *vm;

    bool console = false;
    bool fs = false;

public:
    MiniSystem(StreamIf<std::string> *cif = nullptr, FileIf *fif = nullptr);
    ~MiniSystem();

    int eval(std::string prog);
};