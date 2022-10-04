#pragma once
#include <duktape.h>

#include <console.hpp>

class MiniSystem
{
private:
    duk_context *ctx;

public:
    MiniSystem(duk_fatal_function fatal_handler = NULL, duk_alloc_function alloc_func = NULL, duk_realloc_function realloc_func = NULL, duk_free_function free_func = NULL, void *heap_udata = NULL);
    ~MiniSystem();

    int eval(const char *);
};