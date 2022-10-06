#pragma once

#include <string>

#include <wren.h>

class FileIf
{
public:
    FileIf(){};
    ~FileIf(){};

    virtual void *open(std::string path, std::string accessType) = 0;
    virtual void close(void *) = 0;
    virtual std::string read(void *, int charCount) = 0;
    virtual void write(void *, std::string) = 0;
    virtual int size(void *) = 0;
    virtual void seek(void *, int pos) = 0;
};

class File
{
private:
    FileIf *fif;

public:
    File(){};
    ~File();

    void init(FileIf *fif);

    void *open(std::string path, std::string accessType);
    void close(void *file);
    std::string read(void *file, int charCount);
    void write(void *file, std::string);
    int size(void *file);
    void seek(void *file, int pos);
};

void fileAllocate(WrenVM *vm);
void fileFinalize(WrenVM *vm);
void fileOpen(WrenVM *vm);
void fileClose(WrenVM *vm);
void fileRead(WrenVM *vm);
void fileWrite(WrenVM *vm);
void fileSize(WrenVM *vm);
void fileSeek(WrenVM *vm);