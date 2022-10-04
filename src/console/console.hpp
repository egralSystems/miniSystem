#pragma once
#include <duktape.h>
#include <stream.hpp>
#include <vector>
#include <string>

extern Stream<std::string> consoleStream;

class Console
{
private:
public:
    static duk_ret_t assert(duk_context *ctx)
    {
        if (duk_get_top(ctx) < 2)
            return DUK_ERR_SYNTAX_ERROR;
        duk_push_string(ctx, " ");
        duk_insert(ctx, 0);
        duk_join(ctx, duk_get_top(ctx) - 1);

        return 0;
    }

    static duk_ret_t clear(duk_context *ctx)
    {
        return 0;
    }

    static duk_ret_t count(duk_context *ctx)
    {
        return 0;
    }

    static duk_ret_t countReset(duk_context *ctx)
    {
        return 0;
    }

    static duk_ret_t debug(duk_context *ctx)
    {
        return 0;
    }

    static duk_ret_t dir(duk_context *ctx)
    {
        return 0;
    }

    static duk_ret_t dirxml(duk_context *ctx)
    {
        return 0;
    }

    static duk_ret_t error(duk_context *ctx)
    {
        if (duk_get_top(ctx) == 0)
        {
            consoleStream << "";
        }

        duk_push_string(ctx, " ");
        duk_insert(ctx, 0);
        duk_join(ctx, duk_get_top(ctx) - 1);

        consoleStream << "ERROR: " + std::string(duk_safe_to_string(ctx, -1));
        return 0;
    }

    static duk_ret_t group(duk_context *ctx)
    {
        return 0;
    }

    static duk_ret_t groupCollapsed(duk_context *ctx)
    {
        return 0;
    }

    static duk_ret_t groupEnd(duk_context *ctx)
    {
        return 0;
    }

    static duk_ret_t info(duk_context *ctx)
    {
        duk_push_string(ctx, " ");
        duk_insert(ctx, 0);
        duk_join(ctx, duk_get_top(ctx) - 1);

        consoleStream << "INFO: " + std::string(duk_safe_to_string(ctx, -1));

        return 0;
    }

    static duk_ret_t log(duk_context *ctx)
    {

        duk_push_string(ctx, " ");
        duk_insert(ctx, 0);
        duk_join(ctx, duk_get_top(ctx) - 1);

        consoleStream << "LOG: " + std::string(duk_safe_to_string(ctx, -1));

        return 0;
    }

    static duk_ret_t table(duk_context *ctx)
    {
        return 0;
    }

    static duk_ret_t time(duk_context *ctx)
    {
        return 0;
    }

    static duk_ret_t timeEnd(duk_context *ctx)
    {
        return 0;
    }

    static duk_ret_t timeLog(duk_context *ctx)
    {
        return 0;
    }

    static duk_ret_t trace(duk_context *ctx)
    {
        return 0;
    }

    static duk_ret_t warn(duk_context *ctx)
    {
        duk_push_string(ctx, " ");
        duk_insert(ctx, 0);
        duk_join(ctx, duk_get_top(ctx) - 1);

        consoleStream << "WARNING: " + std::string(duk_safe_to_string(ctx, -1));

        return 0;
    }
};

void init_console(duk_context *ctx);