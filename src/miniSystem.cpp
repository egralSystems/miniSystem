#include <string>
#include <vector>
#include <cstring>

#include <wren.hpp>

#include "stream.hpp"
#include "fs.hpp"
#include "miniSystem.hpp"

WrenForeignClassMethods bindForeignClass(WrenVM *vm, const char *module, const char *className)
{
    WrenForeignClassMethods methods;

    methods.allocate = nullptr;
    methods.finalize = nullptr;

    if (strcmp(className, "File") == 0)
    {
        methods.allocate = fileAllocate;
        methods.finalize = fileFinalize;
    }

    return methods;
}

WrenForeignMethodFn bindForeignMethod(WrenVM *vm, const char *module, const char *className, bool isStatic, const char *sig)
{
    if (!strcmp(module, "main"))
    {
        if (!strcmp(className, "File"))
        {
            if (!isStatic && !strcmp(sig, "read(_)"))
                return fileRead;
            if (!isStatic && !strcmp(sig, "write(_)"))
                return fileWrite;
            if (!isStatic && !strcmp(sig, "size()"))
                return fileSize;
            if (!isStatic && !strcmp(sig, "seek(_)"))
                return fileSeek;
            if (!isStatic && !strcmp(sig, "close()"))
                return fileClose;
        }
    }

    return nullptr;
}