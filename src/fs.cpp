#include <wren.hpp>

#include "miniSystem.hpp"
#include "fs.hpp"

File::~File() {}

template <typename Fif>
FileIf *File::newFile()
{
    FileIf *fif = (FileIf *)(new Fif);
    return fif;
}

// Important needs to be called at boot!!!
template <typename Fif>
void File::sizeOfFif()
{
    fifSize = sizeof(Fif);
}

void fileAllocate(WrenVM *vm)
{
    FileIf **file = (FileIf **)wrenSetSlotNewForeign(vm, 0, 0, fileSystem.fifSize);

    std::string path = wrenGetSlotString(vm, 1);
    std::string options = wrenGetSlotString(vm, 2);
    (*file)->open(path, options);
}

void fileFinalize(void *data)
{
    FileIf *file = (FileIf *)data;

    file->close();

    delete file;
}

void fileClose(WrenVM *vm)
{
    FileIf **file = (FileIf **)wrenGetSlotForeign(vm, 0);
    (*file)->close();
}

void fileRead(WrenVM *vm)
{
    FileIf **file = (FileIf **)wrenGetSlotForeign(vm, 0);
    int charCount = (int)wrenGetSlotDouble(vm, 1);
    std::string read = (*file)->read(charCount);
    wrenSetSlotString(vm, 0, read.c_str());
}

void fileWrite(WrenVM *vm)
{
    FileIf **file = (FileIf **)wrenGetSlotForeign(vm, 0);
    std::string toWrite = wrenGetSlotString(vm, 1);
    (*file)->write(toWrite);
}

void fileSize(WrenVM *vm)
{
    FileIf **file = (FileIf **)wrenGetSlotForeign(vm, 0);
    wrenSetSlotDouble(vm, 0, (*file)->size());
}

void fileSeek(WrenVM *vm)
{
    FileIf **file = (FileIf **)wrenGetSlotForeign(vm, 0);
    int seekPoint = (int)wrenGetSlotDouble(vm, 1);
    (*file)->seek(seekPoint);
}