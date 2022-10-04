#include <stdio.h>

#include "miniSystem.hpp"

MiniSystem::MiniSystem()
{
    jerry_init(JERRY_INIT_EMPTY);
}

MiniSystem::~MiniSystem()
{
    duk_destroy_heap(ctx);
}

int MiniSystem::eval(const char *prog)
{
    duk_eval_string(ctx, prog);
    return duk_get_int(ctx, duk_get_top(ctx) - 1);
}