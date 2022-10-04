#include "console.hpp"

Stream<std::string> consoleStream;

void init_console(duk_context *ctx)
{
    duk_push_object(ctx);

    duk_push_c_function(ctx, Console::assert, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "assert");

    duk_push_c_function(ctx, Console::clear, 0);
    duk_put_prop_string(ctx, -2, "clear");

    duk_push_c_function(ctx, Console::count, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "count");

    duk_push_c_function(ctx, Console::countReset, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "countReset");

    duk_push_c_function(ctx, Console::debug, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "debug");

    duk_push_c_function(ctx, Console::dir, 1);
    duk_put_prop_string(ctx, -2, "dir");

    duk_push_c_function(ctx, Console::dirxml, 1);
    duk_put_prop_string(ctx, -2, "dirxml");

    duk_push_c_function(ctx, Console::error, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "error");

    duk_push_c_function(ctx, Console::group, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "group");

    duk_push_c_function(ctx, Console::groupCollapsed, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "groupCollapsed");

    duk_push_c_function(ctx, Console::groupEnd, 0);
    duk_put_prop_string(ctx, -2, "groupEnd");

    duk_push_c_function(ctx, Console::info, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "info");

    duk_push_c_function(ctx, Console::log, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "log");

    duk_push_c_function(ctx, Console::table, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "table");

    duk_push_c_function(ctx, Console::time, 1);
    duk_put_prop_string(ctx, -2, "time");

    duk_push_c_function(ctx, Console::timeEnd, 1);
    duk_put_prop_string(ctx, -2, "timeEnd");

    duk_push_c_function(ctx, Console::timeLog, 1);
    duk_put_prop_string(ctx, -2, "timeLog");

    duk_push_c_function(ctx, Console::trace, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "trace");

    duk_push_c_function(ctx, Console::warn, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "warn");

    duk_put_global_string(ctx, "console");
}