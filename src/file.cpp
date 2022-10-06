#include <string>

#include "io.hpp"
#include "file.hpp"

File::File(FileIf *fif)
{
    this->fif = fif;
}

File::~File()
{
    close();
    delete fif;
}

void File::close()
{
    if (open)
    {
        fif->close();
        open = false;
    }
}

std::string File::read(int charCount)
{
    return fif->read(charCount);
}

void File::write(std::string toWrite)
{
    fif->write(toWrite);
}

int File::size()
{
    return fif->size();
}

void File::seek(int pos)
{
    fif->seek(pos);
}

/* WREN interface functions */

void fileAllocate(WrenVM *vm)
{
    File **file = (File **)wrenSetSlotNewForeign(vm, 0, 0, sizeof(File *));

    IOIfs *ioIfs = (IOIfs *)wrenGetUserData(vm);

    std::string path = wrenGetSlotString(vm, 1);
    std::string options = wrenGetSlotString(vm, 2);

    *file = ioIfs->fileSystem.open(path, options);
}

void fileFinalize(void *data)
{
    File **file = (File **)data;

    delete (*file);
    *file = nullptr;
}

void fileClose(WrenVM *vm)
{
    File **file = (File **)wrenGetSlotForeign(vm, 0);
    (*file)->close();
}

void fileRead(WrenVM *vm)
{
    File **file = (File **)wrenGetSlotForeign(vm, 0);
    int charCount = (int)wrenGetSlotDouble(vm, 1);
    std::string read = (*file)->read(charCount);
    wrenSetSlotString(vm, 0, read.c_str());
}

void fileWrite(WrenVM *vm)
{
    File **file = (File **)wrenGetSlotForeign(vm, 0);
    std::string toWrite = wrenGetSlotString(vm, 1);
    (*file)->write(toWrite);
}

void fileSize(WrenVM *vm)
{
    File **file = (File **)wrenGetSlotForeign(vm, 0);
    wrenSetSlotDouble(vm, 0, (*file)->size());
}

void fileSeek(WrenVM *vm)
{
    File **file = (File **)wrenGetSlotForeign(vm, 0);
    int seekPoint = (int)wrenGetSlotDouble(vm, 1);
    (*file)->seek(seekPoint);
}