#pragma once

#include <stdio.h>
#include <duktape.h>

duk_ret_t console_assert(duk_context *ctx)
{
    return 0;
}

duk_ret_t console_clear(duk_context *ctx)
{
    return 0;
}

duk_ret_t console_count(duk_context *ctx)
{
    return 0;
}

duk_ret_t console_countReset(duk_context *ctx)
{
    return 0;
}

duk_ret_t console_debug(duk_context *ctx)
{
    return 0;
}

duk_ret_t console_dir(duk_context *ctx)
{
    return 0;
}

duk_ret_t console_dirxml(duk_context *ctx)
{
    return 0;
}

duk_ret_t console_error(duk_context *ctx)
{
    duk_push_string(ctx, " ");
    duk_insert(ctx, 0);
    duk_join(ctx, duk_get_top(ctx) - 1);
    printf("ERROR: %s\n", duk_safe_to_string(ctx, -1));

    return 0;
}

duk_ret_t console_group(duk_context *ctx)
{
    return 0;
}

duk_ret_t console_groupCollapsed(duk_context *ctx)
{
    return 0;
}

duk_ret_t console_groupEnd(duk_context *ctx)
{
    return 0;
}

duk_ret_t console_info(duk_context *ctx)
{
    duk_push_string(ctx, " ");
    duk_insert(ctx, 0);
    duk_join(ctx, duk_get_top(ctx) - 1);
    printf("INFO: %s\n", duk_safe_to_string(ctx, -1));

    return 0;
}

duk_ret_t console_log(duk_context *ctx)
{

    duk_push_string(ctx, " ");
    duk_insert(ctx, 0);
    duk_join(ctx, duk_get_top(ctx) - 1);
    printf("%s\n", duk_safe_to_string(ctx, -1));

    return 0;
}

duk_ret_t console_table(duk_context *ctx)
{
    return 0;
}

duk_ret_t console_time(duk_context *ctx)
{
    return 0;
}

duk_ret_t console_timeEnd(duk_context *ctx)
{
    return 0;
}

duk_ret_t console_timeLog(duk_context *ctx)
{
    return 0;
}

duk_ret_t console_trace(duk_context *ctx)
{
    return 0;
}

duk_ret_t console_warn(duk_context *ctx)
{
    duk_push_string(ctx, " ");
    duk_insert(ctx, 0);
    duk_join(ctx, duk_get_top(ctx) - 1);
    printf("WARNING: %s\n", duk_safe_to_string(ctx, -1));

    return 0;
}
