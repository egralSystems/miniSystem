#include <wren.hpp>

#include "miniSystem.hpp"
#include "fs.hpp"

FS::FS() {}

FS::~FS()
{
    if (!fsif)
        return;

    delete fsif;
}

void FS::init(FSIf *fsif)
{
    this->fsif = fsif;
}

File *FS::open(std::string path, std::string options)
{
    return new File(fsif->open(path, options));
}
