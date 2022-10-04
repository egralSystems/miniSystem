#pragma once
#include <jerryscript.h>

#include <console.hpp>

class MiniSystem
{
public:
    MiniSystem();
    ~MiniSystem();

    int eval(const char *);
};