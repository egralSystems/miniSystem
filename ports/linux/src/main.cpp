#include <stdio.h>
#include <miniSystem.hpp>
#include <console.hpp>

#include "console_linux.hpp"

static void fault_handler(void *, const char *msg)
{
    fprintf(stderr, "FATAL: %s\n", (msg ? msg : "no message."));
    fflush(stderr);
    exit(1);
}

int main()
{
    Console console = {
        console_assert,
        console_clear,
        console_count,
        console_countReset,
        console_debug,
        console_dir,
        console_dirxml,
        console_error,
        console_group,
        console_groupCollapsed,
        console_groupEnd,
        console_info,
        console_log,
        console_table,
        console_time,
        console_timeEnd,
        console_timeLog,
        console_trace,
        console_warn};

    printf("Created console.\n");

    MiniSystem ms(fault_handler);

    printf("Created MiniSystem.\n");

    ms.define(console);

    printf("Defined console.\n");

    printf("Result: %d.\n", ms.eval("console.log('Hello world!')"));
}