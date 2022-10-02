#include "console.hpp"

void init_console(duk_context *ctx, Console console)
{
    duk_push_object(ctx);

    duk_push_c_function(ctx, console.assert, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "assert");

    duk_push_c_function(ctx, console.clear, 0);
    duk_put_prop_string(ctx, -2, "clear");

    duk_push_c_function(ctx, console.count, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "count");

    duk_push_c_function(ctx, console.countReset, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "countReset");

    duk_push_c_function(ctx, console.debug, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "debug");

    duk_push_c_function(ctx, console.dir, 1);
    duk_put_prop_string(ctx, -2, "dir");

    duk_push_c_function(ctx, console.dirxml, 1);
    duk_put_prop_string(ctx, -2, "dirxml");

    duk_push_c_function(ctx, console.error, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "error");

    duk_push_c_function(ctx, console.group, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "group");

    duk_push_c_function(ctx, console.groupCollapsed, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "groupCollapsed");

    duk_push_c_function(ctx, console.groupEnd, 0);
    duk_put_prop_string(ctx, -2, "groupEnd");

    duk_push_c_function(ctx, console.info, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "info");

    duk_push_c_function(ctx, console.log, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "log");

    duk_push_c_function(ctx, console.table, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "table");

    duk_push_c_function(ctx, console.time, 1);
    duk_put_prop_string(ctx, -2, "time");

    duk_push_c_function(ctx, console.timeEnd, 1);
    duk_put_prop_string(ctx, -2, "timeEnd");

    duk_push_c_function(ctx, console.timeLog, 1);
    duk_put_prop_string(ctx, -2, "timeLog");

    duk_push_c_function(ctx, console.trace, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "trace");

    duk_push_c_function(ctx, console.warn, DUK_VARARGS);
    duk_put_prop_string(ctx, -2, "warn");

    duk_put_global_string(ctx, "console");
}