#include <stdio.h>

#include "miniSystem.hpp"

MiniSystem::MiniSystem(duk_fatal_function fatal_handler, duk_alloc_function alloc_func, duk_realloc_function realloc_func, duk_free_function free_func, void *heap_udata)
{
    ctx = duk_create_heap(alloc_func, realloc_func, free_func, heap_udata, fatal_handler);
    init_console(ctx);
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