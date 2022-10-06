#pragma once

#include <string>

#include <wren.h>

#include "file.hpp"

class FSIf
{
public:
    FSIf(){};
    ~FSIf(){};

    virtual FileIf *open(std::string path, std::string options);
};

class FS
{
private:
    FSIf *fsif;

public:
    FS();
    ~FS();

    void init(FSIf *fsif);

    File open(std::string path, std::string options);
};