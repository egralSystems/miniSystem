#pragma once
#include <duktape.h>

struct Console
{
    duk_c_function assert;
    duk_c_function clear;
    duk_c_function count;
    duk_c_function countReset;
    duk_c_function debug;
    duk_c_function dir;
    duk_c_function dirxml;
    duk_c_function error;
    duk_c_function group;
    duk_c_function groupCollapsed;
    duk_c_function groupEnd;
    duk_c_function info;
    duk_c_function log;
    duk_c_function table;
    duk_c_function time;
    duk_c_function timeEnd;
    duk_c_function timeLog;
    duk_c_function trace;
    duk_c_function warn;
};

void init_console(duk_context *ctx, Console console);