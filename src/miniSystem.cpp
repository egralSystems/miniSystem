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

    Modules *modules = (Modules *)wrenGetUserData(vm);

    if (modules->modules.find(module) != modules->modules.end())
        if (modules->modules[module]->bindClass(&methods, module, className))
            return methods;

    return methods;
}

WrenForeignMethodFn bindForeignMethod(WrenVM *vm, const char *module, const char *className, bool isStatic, const char *sig)
{
    WrenForeignMethodFn potential = nullptr;

    potential = registerFile(className, isStatic, sig);
    if (potential)
        return potential;

    Modules *modules = (Modules *)wrenGetUserData(vm);

    if (modules->modules.find(module) != modules->modules.end())
    {
        potential = modules->modules[module]->bindMethods(className, isStatic, sig);
        if (potential)
            return potential;
    }

    return nullptr;
}
