#pragma once

#include <string>
#include <wren.hpp>

class FileIf
{
public:
    FileIf(){};
    ~FileIf(){};

    virtual void open(std::string path, std::string accessType) = 0;
    virtual void close() = 0;
    virtual std::string read(int charCount) = 0;
    virtual void write(std::string) = 0;
    virtual int size() = 0;
    virtual void seek(int pos) = 0;
};

class File
{
private:
    bool open = true;
    FileIf *fif;

public:
    File(FileIf *fif);
    ~File();

    void close();
    std::string read(int charCount);
    void write(std::string toWrite);
    int size();
    void seek(int pos);
};

void fileAllocate(WrenVM *vm);
void fileFinalize(void *data);
void fileClose(WrenVM *vm);
void fileRead(WrenVM *vm);
void fileWrite(WrenVM *vm);
void fileSize(WrenVM *vm);
void fileSeek(WrenVM *vm);