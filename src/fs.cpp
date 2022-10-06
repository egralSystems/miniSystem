#include <wren.hpp>

#include "fs.hpp"

File::~File()
{
    delete fif;
}

void File::init(FileIf *fif)
{
    this->fif = fif;
}

void *File::open(std::string path, std::string accessType)
{
    return fif->open(path, accessType);
}

void File::close(void *file)
{
    fif->close(file);
}

std::string File::read(void *file, int charCount)
{
    return fif->read(file, charCount);
}

void File::write(void *file, std::string value)
{
    fif->write(file, value);
}

int File::size(void *file)
{
    return fif->size(file);
}

void File::seek(void *file, int pos)
{
    fif->seek(file, pos);
}

void fileAllocate(WrenVM *vm)
{
}

void fileOpen(WrenVM *vm)
{
}

void fileClose(WrenVM *vm)
{
}

void fileRead(WrenVM *vm)
{
}

void fileWrite(WrenVM *vm)
{
}

void fileSize(WrenVM *vm)
{
}

void fileSeek(WrenVM *vm)
{
}