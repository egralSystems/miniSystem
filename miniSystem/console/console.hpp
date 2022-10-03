#pragma once
#include <duktape.h>
#include <stream.hpp>
#include <vector>
#include <string>

extern Stream<char> consoleStream;

struct Console
{
    static duk_ret_t assert(duk_context *ctx)
    {
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
        duk_push_string(ctx, " ");
        duk_insert(ctx, 0);
        duk_join(ctx, duk_get_top(ctx) - 1);

        std::string msg = duk_safe_to_string(ctx, -1);
        msg = "ERROR: " + msg;
        std::vector vmsg(msg.begin(), msg.end());
        consoleStream << vmsg;
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

        std::string msg = duk_safe_to_string(ctx, -1);
        msg = "INFO: " + msg;
        consoleStream << std::vector<char>(msg.begin(), msg.end());

        return 0;
    }

    static duk_ret_t log(duk_context *ctx)
    {

        duk_push_string(ctx, " ");
        duk_insert(ctx, 0);
        duk_join(ctx, duk_get_top(ctx) - 1);

        std::string msg = duk_safe_to_string(ctx, -1);
        msg = "LOG: " + msg;
        consoleStream << std::vector<char>(msg.begin(), msg.end());

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

        std::string msg = duk_safe_to_string(ctx, -1);
        msg = "WARNING: " + msg;
        consoleStream << std::vector<char>(msg.begin(), msg.end());

        return 0;
    }
};

void init_console(duk_context *ctx);